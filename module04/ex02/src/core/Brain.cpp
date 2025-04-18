#include "Brain.hpp"
#include "Color.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
  {
    if (copy._ideas[i].length() > 0)
      this->_ideas[i]= copy._ideas[i];
  }
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		if (other._ideas[i].length() > 0)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

const std::string	Brain::getIdea(size_t i)const
{
	if (i < 100)
		return(this->_ideas[i]);
	else
		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
}

const std::string Brain::getIdeas(void) const {
    std::string result;

    for (int i = 0; i < 100; i++) {
        if (!_ideas[i].empty()) {
            result += _ideas[i] + "\n";
        }
    }
    return result;
}


void	Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << RED << "There is only 100 ideas per brain." << RESET << std::endl;
}
