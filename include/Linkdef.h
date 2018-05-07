#pragma once

#include "include/cp3Types.h"
#include <TROOT.h>
#include <vector>
#include <map>
#include <string>
#include <utility>


#ifdef __MAKECINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;


#pragma link C++ class HH::Lepton+;
#pragma link C++ class HH::Jet+;
#pragma link C++ class HH::Met+;
#pragma link C++ class HH::DileptonMetDijet+;
#pragma link C++ class HH::DileptonMet+;
#pragma link C++ class HH::Dijet+;
#pragma link C++ class HH::MELAAngles+;
#pragma link C++ class HH::Dilepton+;
#pragma link C++ class std::pair<signed char,signed char>+;

#pragma link C++ class std::vector<HH::Lepton>+;
#pragma link C++ class std::vector<HH::Jet>+;
#pragma link C++ class std::vector<HH::Met>+;
#pragma link C++ class std::vector<HH::DileptonMetDijet>+;
#endif
