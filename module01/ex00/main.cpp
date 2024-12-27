#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main() {
  Zombie *z = newZombie("Arnaud");
  z->announce();

  randomChump("Marvin");
  std::cout << "Message pour les explications" << std::endl;
  delete z;
  return 0;
}
