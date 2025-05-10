#include "Bureaucrat.hpp"
#include "Color.hpp"



//canonic
Bureaucrat::Bureaucrat(): _name("Unnamed"), _grade(MAX_GRADE) {
  std::cout << BLUE << "[DEBUG] " << RESET;
  std::cout << "Bureaucrat Default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
  std::cout << BLUE << "[DEBUG ]" << RESET;
  std::cout << "Bureaucrat Copy constructor"<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  std::cout << BLUE << "[DEBUG] " << RESET;
  std::cout << "Bureaucrat assigment operator" << std::endl;

  if(this != &other)
    this->_grade = other._grade;

  return *this;
} 

Bureaucrat::~Bureaucrat() {
  std::cout << BLUE << "[DEBUG] " << RESET;
  std::cout << "Bureaucrat Destructor called" << std::endl;
}

//Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
  std::cout << BLUE << "[DEBUG] " << RESET;
  std::cout << "Bureaucrat Constructor Called" << std::endl;

  if(grade < MIN_GRADE)
      throw GradeTooLowException();
  if(grade > MAX_GRADE)
      throw GradeTooHightException();

  this->_grade = grade;
}

// getter
const std::string& Bureaucrat::getName() const {
  return this->_name;
}

int Bureaucrat::getGrade() const {
  return this->_grade;
}

void Bureaucrat::incrementGrade() {
  if(this->_grade + 1 > 150)
      throw GradeTooHightException();
  ++_grade;
}

void Bureaucrat::decrementGrade() {
  if(this->_grade - 1 < 1) {
    throw GradeTooLowException();
  }
  --_grade;
}

// Exceptions
const char* Bureaucrat::GradeTooHightException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
  o << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
  return o;
}


