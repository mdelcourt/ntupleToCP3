#include "include/ntupleReader.h"
#include <iostream>
using namespace std;


ntupleReader::ntupleReader(string inputFile):fName_(inputFile){
  inputFile_ = new TFile(fName_.c_str());
  if (not inputFile_)
    cerr<<"Unable to open input file!"<<endl;
   
  t_event_        = (TTree* ) inputFile_ ->Get("ntuple/Event");
  t_genParts_     = (TTree* ) inputFile_ ->Get("ntuple/Particle");
  t_genPhotons_   = (TTree* ) inputFile_ ->Get("ntuple/GenPhoton");
  t_vertices_     = (TTree* ) inputFile_ ->Get("ntuple/Vertex");
  t_genJets_      = (TTree* ) inputFile_ ->Get("ntuple/GenJet");
  t_looseElecs_   = (TTree* ) inputFile_ ->Get("ntuple/ElectronLoose");
  t_mediumElecs_  = (TTree* ) inputFile_ ->Get("ntuple/ElectronMedium");
  t_tightElecs_   = (TTree* ) inputFile_ ->Get("ntuple/ElectronTight");
  t_looseMuons_   = (TTree* ) inputFile_ ->Get("ntuple/MuonLoose");
  t_tightMuons_   = (TTree* ) inputFile_ ->Get("ntuple/MuonTight");
  t_allTaus_      = (TTree* ) inputFile_ ->Get("ntuple/TauAll");
  t_puppiJets_    = (TTree* ) inputFile_ ->Get("ntuple/JetPUPPI");
  t_puppiMET_     = (TTree* ) inputFile_ ->Get("ntuple/PuppiMissingET");
  t_loosePhotons_ = (TTree* ) inputFile_ ->Get("ntuple/PhotonLoose");
  t_tightPhotons_ = (TTree* ) inputFile_ ->Get("ntuple/PhotonTight");
 
  attachToMiniEventTree(t_event_, t_genParts_, t_vertices_, t_genJets_, t_genPhotons_, t_looseElecs_, t_mediumElecs_,t_tightElecs_, t_looseMuons_, t_tightMuons_, t_allTaus_,t_puppiJets_, t_puppiMET_,t_loosePhotons_, t_tightPhotons_, ev_);                                  
}

void ntupleReader::GetEntry(long int evtId){
  t_event_        ->GetEntry(evtId) ;   
  t_genParts_     ->GetEntry(evtId) ;   
  t_genPhotons_   ->GetEntry(evtId) ;   
  t_vertices_     ->GetEntry(evtId) ;   
  t_genJets_      ->GetEntry(evtId) ;   
  t_looseElecs_   ->GetEntry(evtId) ;   
  t_mediumElecs_  ->GetEntry(evtId) ;   
  t_tightElecs_   ->GetEntry(evtId) ;   
  t_looseMuons_   ->GetEntry(evtId) ;   
  t_tightMuons_   ->GetEntry(evtId) ;   
  t_allTaus_      ->GetEntry(evtId) ;   
  t_puppiJets_    ->GetEntry(evtId) ;   
  t_puppiMET_     ->GetEntry(evtId) ;   
  t_loosePhotons_ ->GetEntry(evtId) ;   
  t_tightPhotons_ ->GetEntry(evtId) ;   
}

long int ntupleReader::GetEntries(){
  return t_event_->GetEntries();
}


void ntupleReader::Print(){
  cout<<"NeleTight :"<<ev_.nte<<endl;
  for (int ii = 0; ii<ev_.nte; ii++)
    cout<<"pt["<<ii<<"] = "<<ev_.te_pt[ii]<<endl;

}
