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
      throw GradeTooHighException();

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
      throw GradeTooHighException();
  ++_grade;
}

void Bureaucrat::decrementGrade() {
  if(this->_grade - 1 < 1) {
    throw GradeTooLowException();
  }
  --_grade;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << GREEN << "[SIGNED] " << RESET << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "[FAILED] " << RESET << _name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
  o << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
  return o;
}


