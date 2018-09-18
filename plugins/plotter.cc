#include "include/ntupleReader.h"
#include <string>
#include <iostream>
#include "TH1I.h"
#include "TFile.h"
using namespace std;


int main(int argc, char ** argv){
  if (argc < 2){
    std::cerr<<"Error, less than 2 arguments provided. Exiting"<<std::endl;
    return 1;
  }
  
  std::string inputFile(argv[1]);
  std::string outputFile(argv[2]);
  ntupleReader data(inputFile);
  TH1 * hist = new TH1I("Isolation variable", "Isolation variable", 20,0,1);
  TH1 * hist2 = new TH1I("Isolation variable 2", "Isolation variable", 20,0,500);
  for (int i = 0; i < data.GetEntries(); i++){
    data.GetEntry(i);
    //cout<<"Nele : "<<data.ev_.nte<<endl;
    //if (data.ev_.nte < 2)
    //  continue;
    for (int eleId = 0; eleId < data.ev_.nte; eleId++){
    //  cout<<eleId << " : "<<data.ev_.te_relIso[eleId]<<endl;
      hist->Fill(data.ev_.te_relIso[eleId]);
      hist2->Fill(data.ev_.te_relIso[eleId]);
    }
  }
  TFile * f = new TFile(outputFile.c_str(),"RECREATE");
  hist->Write();
  hist2->Write();
  f->Close();


}
