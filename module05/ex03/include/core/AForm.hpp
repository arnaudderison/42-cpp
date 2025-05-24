#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
protected:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSigned;
    const int _gradeToExecute;
    const std::string _target;
    AForm(const AForm& other);

public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& b);
    void checkExecutability(const Bureaucrat& executor) const;

    virtual void execute(const Bureaucrat& executor) const = 0;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& f);
