#include <string>
#include <iostream>
#include <fstream>

int replace(const std::string& str, char **argv) {
  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  std::ofstream out;
  std::string::size_type pos;

  if(str.empty() || s1.empty()) {
    std::cerr << "the file or first argument is empty";
    return 1;
  }

  out.open((filename + ".replace").c_str());
  if(out.fail())
  {
    std::cerr << "Unable to create replace file" << std::endl;
    return 1;
  }

  for(std::string::size_type i = 0; i < str.size(); i++) {
    pos = str.find(s1, i);
    if(pos == i)
    {
      out << s2;
      i += s1.size() - 1;
    } else {
      out << str[i];
    }
  }

  out.close();
  return 0;
}

int main(int argc, char **argv) {
  std::ifstream file;
  std::string str;
  char c;

  if(argc != 4) {
    std::cerr << "Invalide number od argument" << std::endl;
    return 1;
  }
  
  file.open(argv[1]);
  if(file.fail()) {
    std::cerr << "Error : " << argv[1] << "FAILED" << std::endl; 
    return 1;
  }

  while(!file.eof() && file >> std::noskipws >> c)
    str += c;
  file .close();

  return(replace(str, argv));
}
