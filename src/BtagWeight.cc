#include "include/BtagWeight.h"
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

void getBtagSyst(int flav, float pt, vector <float> & w_l, vector <float> & w_h){
  // Filling in Btag systematics in w_l (light) and w_h (heavy) --> nominal, up, down
  // Values taken from here : https://twiki.cern.ch/twiki/pub/CMS/YR2018Systematics/btag_syst_Phase2.txt


  ////////////
  // pt bins

 int npt_syst = 10; 
 float ptinf[] = { 20, 30, 50,  70, 100, 140, 200, 300,  600, 1000 };
 float ptsup[] = { 30, 50, 70, 100, 140, 200, 300, 600, 1000, 3000 };

  ///////////////////////////////
  //
  // The RELATIVE uncertainty (error on efficiency / efficiency)
  // on the DeepCSV tagger efficiency is given below as a function of the jet pt.
  //
  // It is infered from the present b-tagging uncertainty in 2017 (with 42 fb-1), 
  // extrapolated to Phase 2 at 3000 fb-1,
  // taking the statistical part as scaling with 1/sqrt(luminosity) 
  // and assuming the systematics to be reduced by a factor 2
  //
  // Keep a minimum of 0.01 for the Phase 2 relative uncertainty
  //
  // The systematic uncertainty for AK8 subjets are the same as for AK4 jets.
  // It is assumed to be the same for noPU and PU200.
  //
  // For each jet flavour (B, C, L=udsg), the Operating Point corresponds
  // to a udsg mistag = 0.1 (LOOSE), 0.01 (MEDIUM) or 0.001 (TIGHT)
  //
  // Correlation between systematics: 
  // the same rules as for Run 2 have to be followed: 
  //  - syst_C is conservatively taken as correlated to syst_B: 
  //    when varying the b jet tag efficiency by +/- 1 syst_B, 
  //    one has to vary the c jet tag efficiency by +/- 1 syst_C simultaneously. 
  //  - syst_L for light jets is mostly uncorrelated to syst_C and syst_B: 
  //    the light jet tag efficiency can be independently varied by +/-1 syst_L 

 float syst_B_LOOSE[] = {
  0.015, 0.01, 0.01, 0.01, 0.01, 0.01, 0.012, 0.018, 0.021, 0.042 };
 float syst_B_MEDIUM[] = {
  0.017, 0.01, 0.01, 0.01, 0.01, 0.01, 0.016, 0.018, 0.023, 0.046 };
 float syst_B_TIGHT[] = {
  0.018, 0.01, 0.01, 0.01, 0.01, 0.01, 0.016, 0.018, 0.029, 0.058 };

 float syst_C_LOOSE[] = {
  0.039, 0.016, 0.016, 0.015, 0.015, 0.018, 0.03, 0.046, 0.054, 0.107 };
 float syst_C_MEDIUM[] = {
  0.052, 0.021, 0.021, 0.019, 0.02, 0.021, 0.052, 0.055, 0.069, 0.139 };
 float syst_C_TIGHT[] = {
  0.064, 0.029, 0.025, 0.027, 0.028, 0.033, 0.053, 0.064, 0.102, 0.205 };

 float syst_L_LOOSE[] = {
  0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05 };
 float syst_L_MEDIUM[] = {
  0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10 };
 float syst_L_TIGHT[] = {
  0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15 };

  ///////////////////////////////
  // double-b tagger:
  // the following values can be used, independently of the operating point
  // (taking roughly half the Run2 uncertainty)
  // it is only meaningful for AK8 jets with pt > 250 GeV
  
  // float syst_doubleB[] = {
  //  0, 0, 0, 0, 0, 0, 0.02, 0.03, 0.03, 0.06 };

  // getPtBin
  int bin = -1;
  for (int i = 0; i < npt_syst; i++){
     if (pt > ptinf[i])
       bin = i;
     else
       break;
  }
  bool error = false;
  if (bin == -1){
     cerr<<"ERROR, pt = "<<pt<<" too small !"<<endl;
     error = true;
  }
  if (pt > 3000){
     cerr<<"WARNING, pt = "<<pt<<" too high !"<<endl;
     error =true;
  }
  if (flav > 5 || flav < 0){
    cerr<<"ERROR, flav = "<<flav<<" (expecting 0 to 5) "<<endl;
    error = true;
  }
  if (error){
    cerr<<"Setting all btag syst to 1."<<endl;
    // Unable to apply systematics ---> set everything to 1.
    w_h.push_back(1.); 
    w_h.push_back(0.);
    w_h.push_back(0.);
    w_l.push_back(1.); 
    w_l.push_back(0.);
    w_l.push_back(0.);
  }
  else if ( flav < 4 ){
   // Light jet
   // ----> Apply no systematics to w_h
   w_h.push_back(1.); 
   w_h.push_back(0.);
   w_h.push_back(0.);
   float w = syst_L_MEDIUM[bin];
   w_l.push_back(1.);
   w_l.push_back(w);
   w_l.push_back(w);
  }
  else{
    // Heavy jet
    // --> Apply no systematics to w_l
    w_l.push_back(1.); 
    w_l.push_back(0.);
    w_l.push_back(0.);
    float w;
    if (flav == 4)
      w = syst_C_MEDIUM[bin];
    else
      w = syst_B_MEDIUM[bin];

     w_h.push_back(1.);
     w_h.push_back(w);
     w_h.push_back(w);
  }

}



float getBtagEff(float pt, float eta, int pdgId){
    if (pdgId == 5)      {
                                  return (
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 20.00 && pt <= 30.00) * (0.63) +      
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 30.00 && pt <= 40.00) * (0.70) +      
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 40.00 && pt <= 50.00) * (0.74) +      
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 50.00 && pt <= 60.00) * (0.74) +      
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 60.00 && pt <= 70.00) * (0.75) +      
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 70.00 && pt <= 80.00) * (0.75) +      
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 80.00 && pt <= 90.00) * (0.75) +      
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 90.00 && pt <= 100.00) * (0.74) +     
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 100.00 && pt <= 120.00) * (0.73) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 120.00 && pt <= 140.00) * (0.73) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 140.00 && pt <= 160.00) * (0.72) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 160.00 && pt <= 180.00) * (0.69) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 180.00 && pt <= 200.00) * (0.68) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 200.00 && pt <= 250.00) * (0.66) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 250.00 && pt <= 300.00) * (0.64) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 300.00 && pt <= 350.00) * (0.59) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 350.00 && pt <= 400.00) * (0.56) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 400.00 && pt <= 500.00) * (0.50) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 500.00 && pt <= 600.00) * (0.44) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 600.00 && pt <= 700.00) * (0.40) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 700.00 && pt <= 800.00) * (0.32) +    
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 800.00 && pt <= 1000.00) * (0.26) +   
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 1000.00 && pt <= 1400.00) * (0.21) +  
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 1400.00 && pt <= 2000.00) * (0.11) +  
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 2000.00 && pt <= 3000.00) * (0.17) +  
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 3000.00) * (0.00) +                   
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 20.00 && pt <= 30.00) * (0.43) +      
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 30.00 && pt <= 40.00) * (0.53) +      
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 40.00 && pt <= 50.00) * (0.56) +      
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 50.00 && pt <= 60.00) * (0.59) +      
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 60.00 && pt <= 70.00) * (0.60) +      
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 70.00 && pt <= 80.00) * (0.61) +      
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 80.00 && pt <= 90.00) * (0.60) +      
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 90.00 && pt <= 100.00) * (0.59) +     
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 100.00 && pt <= 120.00) * (0.59) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 120.00 && pt <= 140.00) * (0.60) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 140.00 && pt <= 160.00) * (0.58) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 160.00 && pt <= 180.00) * (0.56) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 180.00 && pt <= 200.00) * (0.55) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 200.00 && pt <= 250.00) * (0.53) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 250.00 && pt <= 300.00) * (0.49) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 300.00 && pt <= 350.00) * (0.45) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 350.00 && pt <= 400.00) * (0.42) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 400.00 && pt <= 500.00) * (0.38) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 500.00 && pt <= 600.00) * (0.32) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 600.00 && pt <= 700.00) * (0.36) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 700.00 && pt <= 800.00) * (0.34) +    
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 800.00 && pt <= 1000.00) * (0.29) +   
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 1000.00 && pt <= 1400.00) * (0.20) +  
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 1400.00 && pt <= 2000.00) * (0.00) +  
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 2000.00 && pt <= 3000.00) * (0.00) +  
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 3000.00) * (0.00) +                   
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 20.00 && pt <= 30.00) * (0.25) +      
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 30.00 && pt <= 40.00) * (0.33) +      
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 40.00 && pt <= 50.00) * (0.37) +      
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 50.00 && pt <= 60.00) * (0.39) +      
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 60.00 && pt <= 70.00) * (0.41) +      
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 70.00 && pt <= 80.00) * (0.43) +      
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 80.00 && pt <= 90.00) * (0.41) +      
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 90.00 && pt <= 100.00) * (0.44) +     
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 100.00 && pt <= 120.00) * (0.44) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 120.00 && pt <= 140.00) * (0.42) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 140.00 && pt <= 160.00) * (0.40) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 160.00 && pt <= 180.00) * (0.41) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 180.00 && pt <= 200.00) * (0.39) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 200.00 && pt <= 250.00) * (0.34) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 250.00 && pt <= 300.00) * (0.30) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 300.00 && pt <= 350.00) * (0.23) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 350.00 && pt <= 400.00) * (0.33) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 400.00 && pt <= 500.00) * (0.14) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 500.00 && pt <= 600.00) * (0.00) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 600.00 && pt <= 700.00) * (0.00) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 700.00 && pt <= 800.00) * (0.00) +    
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 800.00 && pt <= 1000.00) * (0.00) +   
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 1000.00 && pt <= 1400.00) * (0.00) +  
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 1400.00 && pt <= 2000.00) * (0.00) +  
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 2000.00 && pt <= 3000.00) * (0.00) +  
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 3000.00) * (0.00)                     
                                  );
                                 }

      else if (pdgId == 4)       {
                                  return(
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 20.00 && pt <= 30.00) * (0.17) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 30.00 && pt <= 40.00) * (0.19) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 40.00 && pt <= 50.00) * (0.20) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 50.00 && pt <= 60.00) * (0.21) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 60.00 && pt <= 70.00) * (0.20) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 70.00 && pt <= 80.00) * (0.20) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 80.00 && pt <= 90.00) * (0.20) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 90.00 && pt <= 100.00) * (0.19) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 100.00 && pt <= 120.00) * (0.18) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 120.00 && pt <= 140.00) * (0.18) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 140.00 && pt <= 160.00) * (0.17) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 160.00 && pt <= 180.00) * (0.16) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 180.00 && pt <= 200.00) * (0.16) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 200.00 && pt <= 250.00) * (0.15) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 250.00 && pt <= 300.00) * (0.12) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 300.00 && pt <= 350.00) * (0.12) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 350.00 && pt <= 400.00) * (0.10) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 400.00 && pt <= 500.00) * (0.08) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 500.00 && pt <= 600.00) * (0.07) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 600.00 && pt <= 700.00) * (0.06) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 700.00 && pt <= 800.00) * (0.05) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 800.00 && pt <= 1000.00) * (0.04) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 1000.00 && pt <= 1400.00) * (0.03) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 1400.00 && pt <= 2000.00) * (0.02) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 2000.00 && pt <= 3000.00) * (0.02) +
                                  (fabs(eta) > 0.00 && fabs(eta) <= 1.50) * (pt > 3000.00) * (0.00) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 20.00 && pt <= 30.00) * (0.08) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 30.00 && pt <= 40.00) * (0.10) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 40.00 && pt <= 50.00) * (0.10) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 50.00 && pt <= 60.00) * (0.12) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 60.00 && pt <= 70.00) * (0.12) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 70.00 && pt <= 80.00) * (0.13) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 80.00 && pt <= 90.00) * (0.13) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 90.00 && pt <= 100.00) * (0.14) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 100.00 && pt <= 120.00) * (0.14) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 120.00 && pt <= 140.00) * (0.14) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 140.00 && pt <= 160.00) * (0.15) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 160.00 && pt <= 180.00) * (0.15) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 180.00 && pt <= 200.00) * (0.15) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 200.00 && pt <= 250.00) * (0.15) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 250.00 && pt <= 300.00) * (0.13) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 300.00 && pt <= 350.00) * (0.12) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 350.00 && pt <= 400.00) * (0.11) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 400.00 && pt <= 500.00) * (0.09) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 500.00 && pt <= 600.00) * (0.07) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 600.00 && pt <= 700.00) * (0.07) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 700.00 && pt <= 800.00) * (0.06) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 800.00 && pt <= 1000.00) * (0.03) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 1000.00 && pt <= 1400.00) * (0.03) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 1400.00 && pt <= 2000.00) * (0.00) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 2000.00 && pt <= 3000.00) * (0.00) +
                                  (fabs(eta) > 1.50 && fabs(eta) <= 2.50) * (pt > 3000.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 20.00 && pt <= 30.00) * (0.06) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 30.00 && pt <= 40.00) * (0.07) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 40.00 && pt <= 50.00) * (0.08) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 50.00 && pt <= 60.00) * (0.08) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 60.00 && pt <= 70.00) * (0.09) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 70.00 && pt <= 80.00) * (0.09) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 80.00 && pt <= 90.00) * (0.10) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 90.00 && pt <= 100.00) * (0.09) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 100.00 && pt <= 120.00) * (0.10) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 120.00 && pt <= 140.00) * (0.10) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 140.00 && pt <= 160.00) * (0.10) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 160.00 && pt <= 180.00) * (0.09) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 180.00 && pt <= 200.00) * (0.09) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 200.00 && pt <= 250.00) * (0.10) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 250.00 && pt <= 300.00) * (0.08) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 300.00 && pt <= 350.00) * (0.07) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 350.00 && pt <= 400.00) * (0.07) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 400.00 && pt <= 500.00) * (0.07) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 500.00 && pt <= 600.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 600.00 && pt <= 700.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 700.00 && pt <= 800.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 800.00 && pt <= 1000.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 1000.00 && pt <= 1400.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 1400.00 && pt <= 2000.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 2000.00 && pt <= 3000.00) * (0.00) +
                                  (fabs(eta) > 2.50 && fabs(eta) <= 3.50) * (pt > 3000.00) * (0.00)
                                  );
      }
    else return(0.001);
}


