#include "include/Converter.h"
#include <string>
#include <iostream>
#include <assert.h>

int main(int argc, char ** argv){
  if (argc < 4){
    std::cerr<<"Error, less than 3 arguments provided. Exiting"<<std::endl;
    return 1;
  }
  
  std::string inputFile(argv[1]);
  std::string outputFile(argv[2]);
  float jec = atof(argv[3]);

  assert(jec !=0);

  bool reweightDY = false;

  Converter c(inputFile,outputFile,reweightDY,jec);
  c.testProducer();
}
