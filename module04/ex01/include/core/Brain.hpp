#pragma once

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &other);

		virtual ~Brain();

		Brain &operator=(const Brain &other);

		const std::string getIdea(size_t i)const;
		const std::string getIdeas(void)const;
		void setIdea(size_t i, std::string idea);
};