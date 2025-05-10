#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

#define MAX_GRADE 150
#define MIN_GRADE 1

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

  public:
    //canonic
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    
    //constructor
    Bureaucrat(const std::string& name, int grade);

    //getter
    const std::string& getName() const;
    int getGrade() const;

    //grade update
    void incrementGrade();
    void decrementGrade();

    //jobs
    void signForm(Form& form) const;

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
          virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

