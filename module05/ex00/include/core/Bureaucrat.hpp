#pragma once

#include <string>
#include <iostream>
#include <exception>

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
    
    //contructor
    Bureaucrat(const std::name, int grade);

    //getter
    const std::string& getName() const;
    int getGrade() const;

    //grade update
    void incrementGrade();
    void decrementGrade();

    class GradeTooHightException : public std::exception {
      public:
        virtual const char* what() const throw();
    }

    class GradeTooLowException : public std::exception {
      public:
          virtual const char* what() const throw();
    }
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

