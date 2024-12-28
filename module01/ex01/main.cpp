#include "Zombie.hpp"


Zombie* zombieHord(int N, std::string name);

int main() {
  int size = 10;

  Zombie* horde = zombieHord(size, "Marvin");
  for(int i = 0; i < size; i++)
    horde[i].announce();

  delete [] horde;
  return 0;
}
