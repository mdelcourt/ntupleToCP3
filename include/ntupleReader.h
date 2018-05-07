#pragma once
#include <string>
#include "include/MiniEvent.h"
#include "TFile.h"
#include "TTree.h"


class ntupleReader{
  private:
    std::string fName_;
    TFile * inputFile_;

    TTree *  t_event_         ;      
    TTree *  t_genParts_      ;      
    TTree *  t_genPhotons_    ;      
    TTree *  t_vertices_      ;      
    TTree *  t_genJets_       ;      
    TTree *  t_looseElecs_    ;      
    TTree *  t_mediumElecs_   ;      
    TTree *  t_tightElecs_    ;      
    TTree *  t_looseMuons_    ;      
    TTree *  t_tightMuons_    ;      
    TTree *  t_allTaus_       ;         
    TTree *  t_puppiJets_     ;      
    TTree *  t_puppiMET_      ;      
    TTree *  t_loosePhotons_  ;   
    TTree *  t_tightPhotons_  ;   


  public:
    ntupleReader(std::string fileIn);

    MiniEvent_t ev_;
    void GetEntry(long int evtId);
    long int GetEntries(); 
    void Print();

};
