#pragma once
#include <string>
#include "include/ntupleReader.h"
#include "include/cp3Builder.h"


class Converter{
  private:
   ntupleReader input_;
   MiniEvent_t *  ev_;
   cp3Builder   bd_;
   std::string fileOut_;
  
  public:
    Converter(std::string fileIn, std::string fileOut, bool reweightBtag = true);
    
    void test();
    void testProducer();
};


