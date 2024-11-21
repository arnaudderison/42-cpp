/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:02:52 by aderison          #+#    #+#             */
/*   Updated: 2024/11/20 01:13:24 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Repertory.hpp"

int main()
{
    PhoneBook phoneBook;
    str line;

    system("clear");
    std::cout << "Hello ! Welcome to your new contact manager." << std::endl;
    while (42)
	{
		std::cout << "Type ADD, SEARCH or EXIT : ";
		std::getline(std::cin, line);

		if (!line.compare("ADD"))
			phoneBook.add_contact();
		else if (!line.compare("SEARCH"))
			phoneBook.search_contact();
		else if (!line.compare("EXIT"))
		{
			std::cout << "Goodbye !" << std::endl;
			break;
		}
		system("clear");
	}
    return 0;
}