#include "include/Converter.h"
#include <iostream>


Converter::Converter(std::string fileIn, std::string fileOut):
  input_(fileIn),ev_(&input_.ev_),bd_(ev_,fileIn),fileOut_(fileOut){
  std::cout<<"Constructor"<<std::endl;
}


void Converter::test(){
  std::cout<<"Test"<<std::endl;
  for (int i = 0; i < 5; i++){
    input_.GetEntry(i);
//    input_.Print();
    std::cout<<"---------"<<std::endl;
    bd_.Build();
    bd_.Print();
  }
}

void Converter::testProducer(){
  TFile * f = new TFile(fileOut_.c_str(),"RECREATE");
  TTree * myTree = new TTree;
  bd_.InitializeTree(myTree);
  for (int i = 0; i  < input_.GetEntries() ; i++){
    if (i%10000 == 0)
      std::cout<<i<<std::endl;
    input_.GetEntry(i);
    bd_.Build();
    bd_.Write(myTree);
  }
  std::cout<<"Left event loop"<<std::endl;
  f->cd();
  std::cout<<"Moved to file 'f'... Writing..."<<std::endl;
  myTree->Write("t");
  std::cout<<"DONE ! :)"<<std::endl;
  std::cout<<"Adding meta-data..."<<std::endl;
  bd_.SaveMetadata();
  f->Close();
}
