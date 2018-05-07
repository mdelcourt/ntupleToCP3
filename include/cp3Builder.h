#pragma once
#include "TTree.h"
#include "TFile.h"
#include "include/MiniEvent.h"
#include "include/cp3Types.h"
#include "include/Tools.h"
#include "include/lester_mt2_bisect.h"

#include <vector>
class cp3Builder{
  private:
    MiniEvent_t * ev;

    void clean();
    void BuildLeptons();
    void BuildDiLeptons();
    void BuildJets();
    void BuildDiJets();
    void BuildMet();
    void BuildllMet();
    void BuildllMetjj();
    void GetEventVariables();

    float HT_;
    int nBJets_, nMuons_, nElectrons_, nJets_;

    float  event_weight             ;
    float  sum_event_weight         ;
    float  event_pu_weight          ;
    bool hh_mumu_category         ;
    bool hh_mumu_fire_trigger_cut ;
    bool hh_muel_category         ;
    bool hh_muel_fire_trigger_cut ;
    bool hh_elmu_category         ;
    bool hh_elmu_fire_trigger_cut ;
    bool hh_elel_category         ;
    bool hh_elel_fire_trigger_cut ;
    HH::LorentzVector met_p4;
    std::vector < HH::Lepton   >   HHLept_  ;
    std::vector < HH::Jet      >   HHJet_   ;
    std::vector < HH::Dijet    >   HHDiJet_   ;
    std::vector < HH::Dilepton >   HHDiLept_;
    std::vector < HH::Met >        HHMet_;
    std::vector < HH::DileptonMet> HHllMet_;
    std::vector < HH::DileptonMetDijet> HHllMetjj_;

  public:
    cp3Builder(MiniEvent_t * e_);
    void Build();
    void InitializeTree(TTree *t);
    void Write(TTree * t);
    void Print(); 
    void SaveMetadata();
    
};


