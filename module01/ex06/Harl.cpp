#include "Harl.hpp"

Harl::Harl() {
  std::cout << "Create an Harl" << std::endl;
}

Harl::~Harl() {
  std::cout << "Harl is destroyed..." << std::endl;
}

void Harl::debug() {
  std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
  std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
  std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
  std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now" << std::endl;
}

int is_message(std::string message) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for(int i = 0; i < 4; i++) {
    if(levels[i] == message)
        return i;
  }

  return -1;
}

void Harl::complain(std::string level) {
  switch(is_message(level)) {
    case(0):
      this->debug();
      //fallthrough
    case(1):
      this->info();
      //fallthrough
    case(2):
      this->warning();
      //fallthrough
    case(3):
      this->error();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
      break;
  }
}

