#include "include/cp3Builder.h"
#include "Math/GenVector/VectorUtil.h"
#include "TFile.h"
#include "TParameter.h"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace HH;

cp3Builder::cp3Builder(MiniEvent_t * e_){
  ev=e_;
  sum_event_weight = 0;
}

void cp3Builder::clean(){
  HHLept_.clear(); 
  HHJet_.clear(); 
  HHDiLept_.clear();
  HHDiJet_.clear();
  HHMet_.clear();
  HHllMet_.clear();
  HHllMetjj_.clear();
}

void cp3Builder::Build(){
  clean();
  BuildLeptons();
  BuildDiLeptons();
  BuildJets();
  BuildDiJets();
  BuildMet();
  BuildllMet();
  BuildllMetjj();
  GetEventVariables();
}



void cp3Builder::BuildLeptons(){
  //Start with electrons.
  //FIXME : Why so tight ?
  for (int eleId = 0; eleId < ev->nte; eleId++){
    Lepton l;
    l.p4 = LorentzVector(ev->te_pt[eleId],ev->te_eta[eleId],ev->te_phi[eleId],ev->te_mass[eleId]);
    l.p4.SetE(sqrt(pow(l.p4.P(),2) + pow(ev->te_mass[eleId],2)));
    l.isEl = true;
    l.charge = ev->te_ch[eleId];
    HHLept_.push_back(l);
  }
  // And now, muons. FIXME: tight ?

  for (int muonId = 0; muonId < ev->ntm; muonId++){
    Lepton l;
    l.p4= LorentzVector(ev->tm_pt[muonId],ev->tm_eta[muonId],ev->tm_phi[muonId],ev->tm_mass[muonId]);
    l.p4.SetE(sqrt(pow(l.p4.P(),2) + pow(ev->tm_mass[muonId],2)));
//    l.p4.SetPtEtaPhiM(ev->te_pt[eleId],ev->te_eta[eleId],ev->te_phi[eleId],ev->te_mass[eleId]);
    l.isMu = true;
    l.charge = ev->tm_ch[muonId];
    HHLept_.push_back(l);
  }
   std::sort(HHLept_.begin(), HHLept_.end(), [](const HH::Lepton& lep1, const HH::Lepton& lep2) { return lep1.p4.Pt() > lep2.p4.Pt(); });
}

void cp3Builder::BuildJets(){
  for (int jetId = 0; jetId < ev->nj ; jetId++){
    Jet j;
    j.p4 = LorentzVector(ev->j_pt[jetId],ev->j_eta[jetId],ev->j_phi[jetId],ev->j_mass[jetId]);
    j.p4.SetE(sqrt(pow(j.p4.P(),2) + pow(ev->j_mass[jetId],2)));
    j.btag_M = (bool) ev->j_mvav2[jetId];
    HHJet_.push_back(j);
  }

}

void cp3Builder::BuildDiLeptons(){
  LorentzVector null_p4(0., 0., 0., 0.);
  for (unsigned int ilep1 = 0; ilep1 < HHLept_.size(); ilep1++){
    for (unsigned int ilep2 = ilep1 + 1; ilep2 < HHLept_.size(); ilep2++){
      HH::Dilepton dilep;

      dilep.p4 = HHLept_[ilep1].p4 + HHLept_[ilep2].p4;
      dilep.ilep1 = ilep1;
      dilep.ilep2 = ilep2;
      dilep.isOS = HHLept_[ilep1].charge* HHLept_[ilep2].charge < 0;
      dilep.isPlusMinus = HHLept_[ilep1].charge > 0 && HHLept_[ilep2].charge < 0;
      dilep.isMinusPlus = HHLept_[ilep1].charge < 0 && HHLept_[ilep2].charge > 0;
      dilep.isMuMu = HHLept_[ilep1].isMu && HHLept_[ilep2].isMu;
      dilep.isElEl = HHLept_[ilep1].isEl && HHLept_[ilep2].isEl;
      dilep.isElMu = HHLept_[ilep1].isEl && HHLept_[ilep2].isMu;
      dilep.isMuEl = HHLept_[ilep1].isMu && HHLept_[ilep2].isEl;
      dilep.isSF = dilep.isMuMu || dilep.isElEl;
      dilep.DR_l_l = ROOT::Math::VectorUtil::DeltaR(HHLept_[ilep1].p4, HHLept_[ilep2].p4);
      dilep.DPhi_l_l = fabs(ROOT::Math::VectorUtil::DeltaPhi(HHLept_[ilep1].p4, HHLept_[ilep2].p4));
      dilep.ht_l_l = HHLept_[ilep1].p4.Pt() + HHLept_[ilep2].p4.Pt();
      dilep.gen_matched = HHLept_[ilep1].gen_matched && HHLept_[ilep2].gen_matched;
      dilep.gen_p4 = dilep.gen_matched ? HHLept_[ilep1].gen_p4 + HHLept_[ilep2].gen_p4 : null_p4;
      dilep.gen_DR = dilep.gen_matched ? ROOT::Math::VectorUtil::DeltaR(dilep.p4, dilep.gen_p4) : -1.;
      dilep.gen_DPtOverPt = dilep.gen_matched ? (dilep.p4.Pt() - dilep.gen_p4.Pt()) / dilep.p4.Pt() : -10.;

      HHDiLept_.push_back(dilep); 
    }
  }
}

void cp3Builder::BuildMet(){
  HH::Met myMet;
  //FIXME energy/Mass for met ?
  myMet.p4 = LorentzVector(ev->met_pt[0],ev->met_eta[0],ev->met_phi[0],ev->met_pt[0]);
  HHMet_.push_back(myMet);
}


void cp3Builder::BuildllMet(){
  LorentzVector null_p4(0., 0., 0., 0.);
  for (unsigned int ill = 0; ill < HHDiLept_.size(); ill++){
    HH::DileptonMet myllmet;
    
    myllmet.p4 = HHDiLept_[ill].p4 + HHMet_[0].p4;
    // blind copy of the ll content
    myllmet.idxs = std::make_pair(HHDiLept_[ill].idxs.first, HHDiLept_[ill].idxs.second);
    myllmet.ilep1 = HHDiLept_[ill].ilep1;
    myllmet.ilep2 = HHDiLept_[ill].ilep2;
    myllmet.isOS = HHDiLept_[ill].isOS;
    myllmet.isPlusMinus = HHDiLept_[ill].isPlusMinus;
    myllmet.isMinusPlus = HHDiLept_[ill].isMinusPlus;
    myllmet.isMuMu = HHDiLept_[ill].isMuMu;
    myllmet.isElEl = HHDiLept_[ill].isElEl;
    myllmet.isElMu = HHDiLept_[ill].isElMu;
    myllmet.isMuEl = HHDiLept_[ill].isMuEl;
    myllmet.isSF = HHDiLept_[ill].isSF;
    myllmet.DR_l_l = HHDiLept_[ill].DR_l_l;
    myllmet.DPhi_l_l = HHDiLept_[ill].DPhi_l_l;
    myllmet.ht_l_l = HHDiLept_[ill].ht_l_l;
    
    // content specific to HH:DileptonMet
    myllmet.ill = ill;
    myllmet.imet = 0;
//    myllmet.isNoHF = HHMet_[0].isNoHF;
    
    float dphi = fabs(ROOT::Math::VectorUtil::DeltaPhi(HHDiLept_[ill].p4, HHMet_[0].p4));
    myllmet.DPhi_ll_met = dphi;
    float mindphi = std::min(fabs(ROOT::Math::VectorUtil::DeltaPhi(HHLept_[HHDiLept_[ill].ilep1].p4, HHMet_[0].p4)), fabs(ROOT::Math::VectorUtil::DeltaPhi(HHLept_[HHDiLept_[ill].ilep2].p4, HHMet_[0].p4)));
    myllmet.minDPhi_l_met = mindphi; 
    float maxdphi = std::max(fabs(ROOT::Math::VectorUtil::DeltaPhi(HHLept_[HHDiLept_[ill].ilep1].p4, HHMet_[0].p4)), fabs(ROOT::Math::VectorUtil::DeltaPhi(HHLept_[HHDiLept_[ill].ilep2].p4, HHMet_[0].p4)));
    myllmet.maxDPhi_l_met = maxdphi;

    myllmet.MT = (HHDiLept_[ill].p4 + HHMet_[0].p4).M(); //WTF ??? Can't process this line...

    myllmet.MT_formula = std::sqrt(2 * HHDiLept_[ill].p4.Pt() * HHMet_[0].p4.Pt() * (1-std::cos(dphi)));
    myllmet.projectedMet = mindphi >= M_PI ? HHMet_[0].p4.Pt() : HHMet_[0].p4.Pt() * std::sin(mindphi);
    myllmet.gen_matched = HHDiLept_[ill].gen_matched && HHMet_[0].gen_matched;
    myllmet.gen_p4 = myllmet.gen_matched ? HHDiLept_[ill].gen_p4 + HHMet_[0].gen_p4 : null_p4;
    myllmet.gen_DR = myllmet.gen_matched ? ROOT::Math::VectorUtil::DeltaR(myllmet.p4, myllmet.gen_p4) : -1.;
    myllmet.gen_DPhi = myllmet.gen_matched ? fabs(ROOT::Math::VectorUtil::DeltaPhi(myllmet.p4, myllmet.gen_p4)) : -1.;
    myllmet.gen_DPtOverPt = myllmet.gen_matched ? (myllmet.p4.Pt() - myllmet.gen_p4.Pt()) / myllmet.p4.Pt() : -10.;
    
    HHllMet_.push_back(myllmet);
  }
  
}

void cp3Builder::BuildDiJets(){
  LorentzVector null_p4(0., 0., 0., 0.);
  for (unsigned int ijet1 = 0; ijet1 < HHJet_.size(); ijet1++) {                      
    for (unsigned int ijet2 = ijet1 + 1; ijet2 < HHJet_.size(); ijet2++) {        
            HH::Dijet myjj;                                                     
            myjj.p4 = HHJet_[ijet1].p4 + HHJet_[ijet2].p4;                          
            myjj.idxs = std::make_pair(HHJet_[ijet1].idx, HHJet_[ijet2].idx);       
            myjj.ijet1 = ijet1;                                                 
            myjj.ijet2 = ijet2;                                                 
            myjj.btag_MM = HHJet_[ijet1].btag_M && HHJet_[ijet2].btag_M;            
            myjj.sumCSV = HHJet_[ijet1].CSV + HHJet_[ijet2].CSV;                    
            myjj.sumCMVAv2 = HHJet_[ijet1].CMVAv2 + HHJet_[ijet2].CMVAv2;           
            myjj.DR_j_j = ROOT::Math::VectorUtil::DeltaR(HHJet_[ijet1].p4, HHJet_[ijet2].p4);
            myjj.DPhi_j_j = fabs(ROOT::Math::VectorUtil::DeltaPhi(HHJet_[ijet1].p4, HHJet_[ijet2].p4));
            myjj.ht_j_j = HHJet_[ijet1].p4.Pt() + HHJet_[ijet2].p4.Pt();            
            myjj.gen_matched_bbPartons = HHJet_[ijet1].gen_matched_bParton && HHJet_[ijet2].gen_matched_bParton;
            myjj.gen_matched_bbHadrons = HHJet_[ijet1].gen_matched_bHadron && HHJet_[ijet2].gen_matched_bHadron;
            myjj.gen_matched = HHJet_[ijet1].gen_matched && HHJet_[ijet2].gen_matched;
            myjj.gen_p4 = myjj.gen_matched ? HHJet_[ijet1].gen_p4 + HHJet_[ijet2].gen_p4 : null_p4;
            myjj.gen_DR = myjj.gen_matched ? ROOT::Math::VectorUtil::DeltaR(myjj.p4, myjj.gen_p4) : -1.;
            myjj.gen_DPtOverPt = myjj.gen_matched ? (myjj.p4.Pt() - myjj.gen_p4.Pt()) / myjj.p4.Pt() : -10.;
            myjj.gen_bb = (HHJet_[ijet1].gen_b && HHJet_[ijet2].gen_b);             
            myjj.gen_bc = (HHJet_[ijet1].gen_b && HHJet_[ijet2].gen_c) || (HHJet_[ijet1].gen_c && HHJet_[ijet2].gen_b);
            myjj.gen_bl = (HHJet_[ijet1].gen_b && HHJet_[ijet2].gen_l) || (HHJet_[ijet1].gen_l && HHJet_[ijet2].gen_b);
            myjj.gen_cc = (HHJet_[ijet1].gen_c && HHJet_[ijet2].gen_c);             
            myjj.gen_cl = (HHJet_[ijet1].gen_c && HHJet_[ijet2].gen_l) || (HHJet_[ijet1].gen_l && HHJet_[ijet2].gen_c);
            myjj.gen_ll = (HHJet_[ijet1].gen_l && HHJet_[ijet2].gen_l);             
            HHDiJet_.push_back(myjj);                                                 
    }                                                                           
  }                                    
  std::sort(HHDiJet_.begin(), HHDiJet_.end(), [&](HH::Dijet& a, HH::Dijet& b){return a.p4.Pt() > b.p4.Pt();});
}

void cp3Builder::BuildllMetjj(){
  LorentzVector null_p4(0., 0., 0., 0.);
  for (unsigned int illmet = 0; illmet < HHllMet_.size(); illmet++)
  {
   for (unsigned int ijj = 0; ijj < HHDiJet_.size(); ijj++)
   {
     unsigned int imet = HHllMet_[illmet].imet;
     unsigned int ill = HHllMet_[illmet].ill;
     unsigned int ijet1 = HHDiJet_[ijj].ijet1;
     unsigned int ijet2 = HHDiJet_[ijj].ijet2;
     unsigned int ilep1 = HHDiLept_[ill].ilep1;
     unsigned int ilep2 = HHDiLept_[ill].ilep2;
     HH::DileptonMetDijet myllmetjj;
     myllmetjj.p4 = HHDiLept_[ill].p4 + HHDiJet_[ijj].p4 + HHMet_[imet].p4;
     myllmetjj.lep1_p4 = HHLept_[ilep1].p4;
     myllmetjj.lep2_p4 = HHLept_[ilep2].p4;
     myllmetjj.jet1_p4 = HHJet_[ijet1].p4;
     myllmetjj.jet2_p4 = HHJet_[ijet2].p4;
     myllmetjj.met_p4 = HHMet_[imet].p4;
     myllmetjj.ll_p4 = HHDiLept_[ill].p4;
     myllmetjj.jj_p4 = HHDiJet_[ijj].p4;
     myllmetjj.lljj_p4 = HHDiLept_[ill].p4 + HHDiJet_[ijj].p4;
     // gen info
     myllmetjj.gen_matched = HHDiLept_[ill].gen_matched && HHDiJet_[ijj].gen_matched && HHMet_[imet].gen_matched;
     myllmetjj.gen_p4 = myllmetjj.gen_matched ? HHDiLept_[ill].gen_p4 + HHDiJet_[ijj].gen_p4 + HHMet_[imet].gen_p4 : null_p4;
     myllmetjj.gen_DR = myllmetjj.gen_matched ? ROOT::Math::VectorUtil::DeltaR(myllmetjj.p4, myllmetjj.gen_p4) : -1.;
     myllmetjj.gen_DPhi = myllmetjj.gen_matched ? fabs(ROOT::Math::VectorUtil::DeltaPhi(myllmetjj.p4, myllmetjj.gen_p4)) : -1.;
     myllmetjj.gen_DPtOverPt = myllmetjj.gen_matched ? (myllmetjj.p4.Pt() - myllmetjj.gen_p4.Pt()) / myllmetjj.p4.Pt() : -10.;
     myllmetjj.gen_lep1_p4 = HHLept_[ilep1].gen_p4;
     myllmetjj.gen_lep2_p4 = HHLept_[ilep2].gen_p4;
     myllmetjj.gen_jet1_p4 = HHJet_[ijet1].gen_p4;
     myllmetjj.gen_jet2_p4 = HHJet_[ijet2].gen_p4;
     myllmetjj.gen_met_p4 = HHMet_[imet].gen_p4;
     myllmetjj.gen_ll_p4 = HHDiLept_[ill].gen_p4;
     myllmetjj.gen_jj_p4 = HHDiJet_[ijj].gen_p4;
     myllmetjj.gen_lljj_p4 = HHDiLept_[ill].gen_p4 + HHDiJet_[ijj].gen_p4;
     // blind copy of the jj content
     myllmetjj.ijet1 = HHDiJet_[ijj].ijet1;
     myllmetjj.ijet2 = HHDiJet_[ijj].ijet2;
     myllmetjj.btag_MM = HHDiJet_[ijj].btag_MM;
     myllmetjj.sumCSV = HHDiJet_[ijj].sumCSV;
     myllmetjj.sumCMVAv2 = HHDiJet_[ijj].sumCMVAv2;
     myllmetjj.DR_j_j = HHDiJet_[ijj].DR_j_j;
     myllmetjj.DPhi_j_j = HHDiJet_[ijj].DPhi_j_j;
     myllmetjj.ht_j_j = HHDiJet_[ijj].ht_j_j;
     myllmetjj.gen_matched_bbPartons = HHDiJet_[ijj].gen_matched_bbPartons;
     myllmetjj.gen_matched_bbHadrons = HHDiJet_[ijj].gen_matched_bbHadrons;
     myllmetjj.gen_bb = HHDiJet_[ijj].gen_bb;
     myllmetjj.gen_bc = HHDiJet_[ijj].gen_bc;
     myllmetjj.gen_bl = HHDiJet_[ijj].gen_bl;
     myllmetjj.gen_cc = HHDiJet_[ijj].gen_cc;
     myllmetjj.gen_cl = HHDiJet_[ijj].gen_cl;
     myllmetjj.gen_ll = HHDiJet_[ijj].gen_ll;
     // blind copy of the llmet content
     myllmetjj.ilep1 = HHDiLept_[ill].ilep1;
     myllmetjj.ilep2 = HHDiLept_[ill].ilep2;
     myllmetjj.isOS = HHDiLept_[ill].isOS;
     myllmetjj.isPlusMinus = HHDiLept_[ill].isPlusMinus;
     myllmetjj.isMinusPlus = HHDiLept_[ill].isMinusPlus;
     myllmetjj.isMuMu = HHDiLept_[ill].isMuMu;
     myllmetjj.isElEl = HHDiLept_[ill].isElEl;
     myllmetjj.isElMu = HHDiLept_[ill].isElMu;
     myllmetjj.isMuEl = HHDiLept_[ill].isMuEl;
     myllmetjj.isSF = HHDiLept_[ill].isSF;
     myllmetjj.DR_l_l = HHDiLept_[ill].DR_l_l;
     myllmetjj.DPhi_l_l = HHDiLept_[ill].DPhi_l_l;
     myllmetjj.ht_l_l = HHDiLept_[ill].ht_l_l;
     myllmetjj.trigger_efficiency = HHDiLept_[ill].trigger_efficiency;
     myllmetjj.trigger_efficiency_downVariated = HHDiLept_[ill].trigger_efficiency_downVariated;
     myllmetjj.trigger_efficiency_upVariated = HHDiLept_[ill].trigger_efficiency_upVariated;
     //myllmetjj.ill = ill;
     myllmetjj.imet = imet;
     myllmetjj.isNoHF = HHMet_[imet].isNoHF;
     myllmetjj.DPhi_ll_met = HHllMet_[illmet].DPhi_ll_met;
     myllmetjj.minDPhi_l_met = HHllMet_[illmet].minDPhi_l_met; 
     myllmetjj.maxDPhi_l_met = HHllMet_[illmet].maxDPhi_l_met;
     myllmetjj.MT = HHllMet_[illmet].MT;
     myllmetjj.MT_formula = HHllMet_[illmet].MT_formula;
     myllmetjj.projectedMet = HHllMet_[illmet].projectedMet;
     // content specific to HH::DijetMet
     // NB: computed for the first time here, no intermediate jjmet collection
     myllmetjj.DPhi_jj_met = fabs(ROOT::Math::VectorUtil::DeltaPhi(HHDiJet_[ijj].p4, HHMet_[imet].p4));
     myllmetjj.minDPhi_j_met = std::min(fabs(ROOT::Math::VectorUtil::DeltaPhi(HHJet_[HHDiJet_[ijj].ijet1].p4, HHMet_[imet].p4)), fabs(ROOT::Math::VectorUtil::DeltaPhi(HHJet_[HHDiJet_[ijj].ijet2].p4, HHMet_[imet].p4)));
     myllmetjj.maxDPhi_j_met = std::max(fabs(ROOT::Math::VectorUtil::DeltaPhi(HHJet_[HHDiJet_[ijj].ijet1].p4, HHMet_[imet].p4)), fabs(ROOT::Math::VectorUtil::DeltaPhi(HHJet_[HHDiJet_[ijj].ijet2].p4, HHMet_[imet].p4)));
     // content specific to HH::DileptonMetDijet
     float DR_j1l1, DR_j1l2, DR_j2l1, DR_j2l2;
     DR_j1l1 = ROOT::Math::VectorUtil::DeltaR(HHJet_[ijet1].p4, HHLept_[ilep1].p4);
     DR_j1l2 = ROOT::Math::VectorUtil::DeltaR(HHJet_[ijet1].p4, HHLept_[ilep2].p4);
     DR_j2l1 = ROOT::Math::VectorUtil::DeltaR(HHJet_[ijet2].p4, HHLept_[ilep1].p4);
     DR_j2l2 = ROOT::Math::VectorUtil::DeltaR(HHJet_[ijet2].p4, HHLept_[ilep2].p4);
     myllmetjj.maxDR_l_j = std::max({DR_j1l1, DR_j1l2, DR_j2l1, DR_j2l2});
     myllmetjj.minDR_l_j = std::min({DR_j1l1, DR_j1l2, DR_j2l1, DR_j2l2});
     myllmetjj.DR_ll_jj = ROOT::Math::VectorUtil::DeltaR(HHDiLept_[ill].p4, HHDiJet_[ijj].p4);
     myllmetjj.DPhi_ll_jj = fabs(ROOT::Math::VectorUtil::DeltaPhi(HHDiLept_[ill].p4, HHDiJet_[ijj].p4));
     myllmetjj.DR_llmet_jj = ROOT::Math::VectorUtil::DeltaR(HHllMet_[illmet].p4, HHDiJet_[ijj].p4);
     myllmetjj.DPhi_llmet_jj = fabs(ROOT::Math::VectorUtil::DeltaPhi(HHllMet_[illmet].p4, HHDiJet_[ijj].p4));
     myllmetjj.cosThetaStar_CS = fabs(getCosThetaStar_CS(HHllMet_[illmet].p4, HHDiJet_[ijj].p4));
     myllmetjj.MT_fullsystem = myllmetjj.p4.Mt();
     myllmetjj.melaAngles = getMELAAngles(HHllMet_[illmet].p4, HHDiJet_[ijj].p4, HHLept_[ilep1].p4, HHLept_[ilep2].p4, HHJet_[ijet1].p4, HHJet_[ijet2].p4);
     myllmetjj.visMelaAngles = getMELAAngles(HHDiLept_[ill].p4, HHDiJet_[ijj].p4, HHLept_[ilep1].p4, HHLept_[ilep2].p4, HHJet_[ijet1].p4, HHJet_[ijet2].p4); // only take the visible part of the H(ww) candidate
  
     // Compute MT2. See https://arxiv.org/pdf/1309.6318v1.pdf and https://arxiv.org/pdf/1411.4312v5.pdf
     double px_invisible = myllmetjj.lep1_p4.px() + myllmetjj.lep2_p4.px() + myllmetjj.met_p4.px();
     double py_invisible = myllmetjj.lep1_p4.py() + myllmetjj.lep2_p4.py() + myllmetjj.met_p4.py();
  
     myllmetjj.MT2 = asymm_mt2_lester_bisect::get_mT2(
             myllmetjj.jet1_p4.M(), myllmetjj.jet1_p4.px(), myllmetjj.jet1_p4.py(),
             myllmetjj.jet2_p4.M(), myllmetjj.jet2_p4.px(), myllmetjj.jet2_p4.py(),
             px_invisible, py_invisible,
             myllmetjj.lep1_p4.M(), myllmetjj.lep2_p4.M(),
             0.5 // Absolute precision
             );
     // Fill
     HHllMetjj_.push_back(myllmetjj);
   }
  }

  //Keep only candidate with highest pt

  std::sort(HHllMetjj_.begin(), HHllMetjj_.end(), [&](HH::DileptonMetDijet& a, const HH::DileptonMetDijet& b){ return a.p4.Pt() > b.p4.Pt(); });
  if(HHllMetjj_.size() > 1 ) {
    HHllMetjj_.resize(1);
  }
  
  
}


void cp3Builder::GetEventVariables(){
    HT_ = 0;
    if (HHllMetjj_.size() > 0)
        HT_ += HHllMetjj_[0].lep1_p4.Pt() + HHllMetjj_[0].lep2_p4.Pt();
    for (unsigned int ijet = 0; ijet < HHJet_.size(); ijet++) {
        HT_ += HHJet_[ijet].p4.Pt();
    }

    nJets_ = HHJet_.size();
    nBJets_ = 0;
    for (unsigned int ijet = 0; ijet < HHJet_.size(); ijet++) {
      if (HHJet_[ijet].btag_M)
          nBJets_++;
    }

    nMuons_ = 0;
    nElectrons_ = 0;
    for (unsigned int ilepton = 0; ilepton < HHLept_.size(); ilepton++)
    {
      if (HHLept_[ilepton].isMu) {
        nMuons_++;
      }
      if (HHLept_[ilepton].isEl) {
        nElectrons_++;
      }
    }

    // Others... TODO:
    if (ev->g_nw > 0 && ev->maxweights > 0)
      event_weight           = ev->g_w[0];
    else
      event_weight           = 1;
    sum_event_weight += event_weight;
    event_pu_weight          = 1;
    hh_mumu_category         = 0;
    hh_mumu_fire_trigger_cut = 0;
    hh_muel_category         = 0;
    hh_muel_fire_trigger_cut = 0;
    hh_elmu_category         = 0;
    hh_elmu_fire_trigger_cut = 0;
    hh_elel_category         = 0;
    hh_elel_fire_trigger_cut = 0;
    if (HHLept_.size() >= 2){
      if (HHLept_[0].isMu){
        if (HHLept_[1].isMu){
          hh_mumu_category = 1;
          if (HHLept_[0].p4.Pt() > 20 && HHLept_[1].p4.Pt() > 10)
            hh_mumu_fire_trigger_cut = 1;
        }
        if (HHLept_[1].isEl){
          hh_muel_category = 1;
          if (HHLept_[0].p4.Pt() > 25 && HHLept_[1].p4.Pt() > 15)
            hh_muel_fire_trigger_cut = 1;
        }
      }
      if (HHLept_[0].isEl){
        if (HHLept_[1].isMu){
          hh_elmu_category = 1;
          if (HHLept_[0].p4.Pt() > 25 && HHLept_[1].p4.Pt() > 10)
            hh_elmu_fire_trigger_cut = 1;
        }
        if (HHLept_[1].isEl){
          hh_elel_category = 1;
          if (HHLept_[0].p4.Pt() > 25 && HHLept_[1].p4.Pt() > 15)
            hh_elel_fire_trigger_cut = 1;
        }
      }
    }



    if (HHMet_.size()!=1)
      cerr<<"Warning, MET size != 1"<<endl;
    else
      met_p4 = HHMet_[0].p4;

}









void cp3Builder::Print(){
  cout<<"-------------------------------------------------------"<<endl;
  for (auto lept : HHLept_){
    if (lept.isMu)
      cout<<" --> Muon ";
    if (lept.isEl)
      cout<<" --> Ele ";
    cout<<"Pt,Eta,Phi,E ="<<lept.p4.Pt()<<","<<lept.p4.Eta()<<","<<lept.p4.Phi()<<","<<lept.p4.E()<<endl;
  }
  for (auto jet : HHJet_){
    if(jet.btag_M) cout<<" --> B-tagged jet ";
    else           cout<<" -->          jet ";
    cout<<"Pt,Eta,Phi,E ="<<jet.p4.Pt()<<","<<jet.p4.Eta()<<","<<jet.p4.Phi()<<","<<jet.p4.E()<<endl;
  }
  cout<<"llMetjj :"<<endl;
  for (auto llmetjj : HHllMetjj_){
     cout<<"Pt,Eta,Phi,E = "<<llmetjj.p4.Pt()<<","<<llmetjj.p4.Eta()<<","<<llmetjj.p4.Phi()<<","<<llmetjj.p4.E()<<endl;
  }
}


void cp3Builder::InitializeTree(TTree * t){
  
  
  t->Branch("hh_leptons"     ,&HHLept_    );
  t->Branch("hh_met"         ,&HHMet_     );
  t->Branch("hh_jets"        ,&HHJet_     );
  t->Branch("hh_llmetjj"     ,&HHllMetjj_ );
  t->Branch("hh_HT"          ,&HT_        );
  t->Branch("hh_nJetsL"      ,&nJets_     );
  t->Branch("hh_nBJetsM"     ,&nBJets_    );
  t->Branch("hh_nMuonsT"     ,&nMuons_    );
  t->Branch("hh_nElectronsM" ,&nElectrons_);
  t->Branch("met_p4"         ,&met_p4     );
  t->Branch("event_weight"               ,&event_weight              );     
  t->Branch("event_pu_weight"            ,&event_pu_weight           );     
  t->Branch("hh_mumu_category"           ,&hh_mumu_category          );     
  t->Branch("hh_mumu_fire_trigger_cut"   ,&hh_mumu_fire_trigger_cut  );     
  t->Branch("hh_muel_category"           ,&hh_muel_category          );     
  t->Branch("hh_muel_fire_trigger_cut"   ,&hh_muel_fire_trigger_cut  );     
  t->Branch("hh_elmu_category"           ,&hh_elmu_category          );     
  t->Branch("hh_elmu_fire_trigger_cut"   ,&hh_elmu_fire_trigger_cut  );     
  t->Branch("hh_elel_category"           ,&hh_elel_category          );     
  t->Branch("hh_elel_fire_trigger_cut"   ,&hh_elel_fire_trigger_cut  );     

  
  /* Missing values :
 * all gen info
 * hh_mumu_category
 * hh_mumu_fire_trigger_cut
 * hh_elel_category
 * hh_elel_fire_trigger_cut
 * hh_elmu_category
 * hh_elmu_fire_trigger_cut
 * hh_muel_category
 * hh_muel_fire_trigger_cut
 */

}

void cp3Builder::Write(TTree * t){
  //Check trigger :
  if (hh_mumu_fire_trigger_cut || hh_muel_fire_trigger_cut || hh_elmu_fire_trigger_cut || hh_elel_fire_trigger_cut) {
    //Check 2 jets
    if (HHJet_.size() >= 2){
      t->Fill();
    }
  }
}

void cp3Builder::SaveMetadata(){
    TParameter <float> myParam("event_weight_sum",sum_event_weight);
    myParam.Write("event_weight_sum");    
}
