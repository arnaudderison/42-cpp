#include "RNP.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  RNP rnp;

  if(argc != 2){
      std::cerr << "Error: bad arguments." << std::endl;
      return 1;
  }

  try{
    std::cout << rnp.evaluate(argv[1]) << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}