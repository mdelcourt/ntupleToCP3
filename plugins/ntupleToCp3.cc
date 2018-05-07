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
//  std::cout<<
  Converter c(inputFile,outputFile);
  c.testProducer();
}