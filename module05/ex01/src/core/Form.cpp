#include "Form.hpp"
#include "Color.hpp"
#include "Bureaucrat.hpp"

//canonic
Form::Form()
  : _name("Unnamed"),
  _isSigned(false),
  _gradeToSigned(150),
  _gradeToExecute(150) {
  std::cout << BLUE << "[DEBUG] " << RESET;
  std::cout << "Form Default construtor" << std::endl;
}

Form::Form(const Form& other)
  :_name(other._name),
  _isSigned(other._isSigned),
  _gradeToSigned(other._gradeToSigned),
  _gradeToExecute(other._gradeToExecute) {
    std::cout << BLUE << "[DEBUG] " << RESET;
    std::cout << "Form copy opearator called" << std::endl;
  }

Form& Form::operator=(const Form& other) {
  std::cout << BLUE << "[DEBUG] " << RESET;
  std::cout << "Form assignement opearator" << std::endl;

  if(this != &other)
    this->_isSigned = other._isSigned;

  return *this;
}

Form::~Form() {
  std::cout << BLUE << "[DEBUG] " << RESET;
  std::cout << "Form Destructor" << std::endl;
}

//construtor 
Form::Form(const std::string& name, int gradeToSigned, int gradeToExecute)
  : _name(name),
  _isSigned(false),
  _gradeToSigned(gradeToSigned),
  _gradeToExecute(gradeToExecute) {
    std::cout << BLUE << "[DEBUG] " << RESET;
    std::cout << "Form Constructor Called" << std::endl;
    if (_gradeToSigned < MIN_GRADE || _gradeToExecute < MIN_GRADE)
        throw GradeTooHighException();
    if (_gradeToSigned > MAX_GRADE || _gradeToExecute > MAX_GRADE)
        throw GradeTooLowException();
  }

//getter
const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSigned; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

//exception 
const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade too low";
}


void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSigned)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& o, const Form& f) {
    o << "Form \"" << f.getName() << "\", signed: "
      << (f.isSigned() ? "yes" : "no")
      << ", grade to sign: " << f.getGradeToSign()
      << ", grade to execute: " << f.getGradeToExecute();
    return o;
}

