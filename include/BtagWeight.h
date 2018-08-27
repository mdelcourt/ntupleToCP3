#pragma once
#include <vector>

float getBtagEff(float pt, float eta, int pdgId);
void getBtagSyst(int flav, float pt, std::vector <float> & w_l, std::vector <float> & w_h);
