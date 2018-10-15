#include <iostream>
#include "include/ntupleReader.h"

using namespace std;

vector <string> pp = {"0","d","u","s","c","b","t","b'","t'","9","10","e","ne","mu","nmu","tau","ntau","tau'","ntau'",
    "19","20","g","gamma","Z","W","H","26","27","28","29","30","31","32"};


int main(){
  for (int i = 0; i < 200; i++)
    pp.push_back("???");
  ntupleReader rd("/home/ucl/cp3/delcourt/storage/HH_HLLHC/DELPHES_YR/GluGluToHHTo2B2VTo2L2Nu_node_SM_14TeV-madgraph_200PU/p2ntuple_GluGluToHHTo2B2VTo2L2Nu_node_SM_14TeV-madgraph_4_0.root");
  for (int i = 0; i < 100; i++){
    cout<<endl<<endl<<endl;
    cout<<"*************** NEW EVENT "<<i<<" ***********************"<<endl;
    rd.GetEntry(i);
    for (int  ji = 0; ji < rd.ev_.ngl; ji++){
         //cout<<"HIGGS DISCOVERED !!! (pt,eta,phi)  = (";
//         if (rd.ev_.gl_st[ji] == 23 || rd.ev_.gl_st[ji] == 1)
           if (rd.ev_.gl_pt[ji] > 1 && rd.ev_.gl_st[ji] != 44 &&  rd.ev_.gl_st[ji] != 52)        
             cout<<"----> Particle "<<pp[abs(rd.ev_.gl_pid[ji])]<<"  "<<"("<<rd.ev_.gl_pt[ji]<<","<<rd.ev_.gl_eta[ji]<<","<<rd.ev_.gl_phi[ji]<<"). Status = "<<rd.ev_.gl_st[ji]<<endl;
//         cout<<"----> Particle "<<rd.ev_.gl_pid[ji]<<"  "<<"("<<rd.ev_.gl_pt[ji]<<","<<rd.ev_.gl_eta[ji]<<","<<rd.ev_.gl_phi[ji]<<"). Status = "<<rd.ev_.gl_st[ji]<<endl;
    }
  }
    

}
