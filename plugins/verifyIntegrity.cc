#include "include/ntupleReader.h"
#include <string>
#include <iostream>
#include "TH1I.h"
#include "TFile.h"
using namespace std;

int main(int argc, char ** argv){
  if (argc < 3){
    std::cerr<<"Error, less than 2 arguments provided. Exiting"<<std::endl;
    return 1;
  }
  
  std::cout<<"Opening "<<argv[1]<<std::endl;
  
  ntupleReader r(argv[1]);
  
  int nEvt = r.GetEntries();


  map<float,int> mapPT;
  map<float,int> mapETA;
  map<float,int> mapPHI;


  for (int i = 0; i<nEvt; i++){
    r.GetEntry(i);
    for (int x = 0; x<r.ev_.ngl; x++){
      if (r.ev_.gl_pt[x] > 0.1)
        mapPT[r.ev_.gl_pt[x]]++; 
      if (abs(r.ev_.gl_eta[x]) < 7)
        mapETA[r.ev_.gl_eta[x]]++;
      if (r.ev_.gl_phi[x] != 0)
        mapPHI[r.ev_.gl_phi[x]]++;
    }
  }
  int bb(0);

  for (auto entry : mapPT){
    if (entry.second > 10){
      cout<<"PT : "<<entry.first<<" ---> "<<entry.second<<endl;
      bb++;
    }
  }
  for (auto entry : mapETA){
    if (entry.second > 10){
      cout<<"ETA : "<<entry.first<<" ---> "<<entry.second<<endl;
      bb++;
    }
  }
  for (auto entry : mapPHI){
    if (entry.second > 1000){
      cout<<"PHI : "<<entry.first<<" ---> "<<entry.second<<endl;
      bb++;
    }
  }


  if (bb == 0)
    cout<<"Nothing to report."<<endl;
  else{
    cout<<"Rerunning to get histograms..."<<endl;
    TH1 * multPT  = new TH1I("PT","PT",5000,0,5000);
    TH1 * multETA = new TH1I("ETA","ETA",5000,0,5000);
    TH1 * multPHI = new TH1I("PHI","PHI",5000,0,5000);
    for (auto entry : mapPT)
      multPT -> Fill(entry.second);
    for (auto entry : mapETA)
      multETA -> Fill(entry.second);
    for (auto entry : mapPHI)
      multPHI -> Fill(entry.second);

    TFile * out = new TFile(argv[2],"RECREATE");
    multPT->Write();
    multETA->Write();
    multPHI->Write();
    out->Close();
  }



}
