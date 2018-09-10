#include "include/Converter.h"
#include <string>
#include <iostream>


int main(int argc, char ** argv){
  if (argc < 3){
    std::cerr<<"Error, less than 2 arguments provided. Exiting"<<std::endl;
    return 1;
  }
  
  std::string inputFile(argv[1]);
  std::string outputFile(argv[2]);

  bool reweightDY = false;
  Converter c(inputFile,outputFile,reweightDY,1.);
  c.testProducer();
}
