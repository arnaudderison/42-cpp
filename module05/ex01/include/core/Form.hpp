#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

#define MAX_GRADE 150
#define MIN_GRADE 1

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSigned;
        const int _gradeToExecute;

    public:
      //canonique
      Form();
      ~Form();
      Form(const Form& other);
      Form& operator=(const Form& other);

      //constructor
      Form(const std::string& name, int gradeToSign, int gradeToExecute);

      //getter
      const std::string& getName() const;
      bool isSigned() const;
      int getGradeToSign() const;
      int getGradeToExecute() const;
      
      //jobs
      void beSigned(const Bureaucrat& b);

      class GradeTooHighException : public std::exception {
        public:
          virtual const char* what() const throw();
      };

      class GradeTooLowException : public std::exception {
        public:
          virtual const char* what() const throw();
      };
};

std::ostream& operator<<(std::ostream& o, const Form& f);
