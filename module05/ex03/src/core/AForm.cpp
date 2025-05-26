#include "AForm.hpp"
#include "Bureaucrat.hpp"

//canonic

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSigned(other._gradeToSigned),
      _gradeToExecute(other._gradeToExecute),
      _target(other._target) 
      {}

AForm& AForm::operator=(const AForm& other) {
  if(this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

AForm::~AForm() {}


AForm::AForm(const std::string& name, int gradeToSigned, int gradeToExecute, const std::string& target)
    : _name(name), _isSigned(false), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute), _target(target)
{
    if (_gradeToSigned < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSigned > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

const std::string& AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSigned; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
const std::string& AForm::getTarget() const { return _target; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSigned)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecutability(const Bureaucrat& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed.";
}

const char* AForm::InvalidFormException::what() const throw() {
    return "Intern try to create unknown form but failed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form " << f.getName() << " [sign grade: " << f.getGradeToSign()
        << ", exec grade: " << f.getGradeToExecute() << ", signed: " << f.getIsSigned() << "]";
    return out;
}
