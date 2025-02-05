#include "Harl.hpp"

int main(int argc, char **argv) {
  Harl test;
  
  if(argc != 2)
      return 1;
  test.complain(argv[1]);
  return 0;
}
