#include <string>
#include <iostream>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string* stringPTR =  &str;
  std::string &stringREF = str;

  std::cout << "Adress of string: " << &str << std::endl;
  std::cout << "Adress held by stringPTR: " << stringPTR << std::endl;
  std::cout << "Adress held by stringREF: " << &stringREF << std::endl;

  std::cout << "Value of the string variable: " << str << std::endl;
  std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
  
  return 0;
}
  
