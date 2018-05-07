#pragma once

#include "include/cp3Types.h"



using namespace HH;
float getCosThetaStar_CS(const LorentzVector & h1, const LorentzVector & h2, float ebeam = 6500);
MELAAngles getMELAAngles(const LorentzVector &q1, const LorentzVector &q2, const LorentzVector &q11, const LorentzVector &q12, const LorentzVector &q21, const LorentzVector &q22,   float ebeam = 6500);


//        void matchOfflineLepton(const HLTProducer& hlt, Dilepton& dilepton);
//        void fillTriggerEfficiencies(const Lepton & lep1, const Lepton & lep2, Dilepton & dilep);

