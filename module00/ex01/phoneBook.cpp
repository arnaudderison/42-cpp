/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:44:20 by aderison          #+#    #+#             */
/*   Updated: 2024/11/21 16:30:03 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Repertory.hpp"

static void ask_question(str question, str& input)
{   
    system("clear");
    std::cout << question;
    std::getline(std::cin, input);
}

static void print_header_tab()
{
    system("clear");

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Laste name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
}

static str trunc_value(const str& value)
{
    if(value.length() > 9)
        return value.substr(0, 9) + ".";
    return value;
}

static void print_contact(Contact& contact)
{
    std::cout << "Name : " << contact.getFirstName() << std::endl;
	std::cout << "Lastname : " << contact.getLasteName() << std::endl;
	std::cout << "Nickname : " << contact.getNickname() << std::endl;
	std::cout << "Phone number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contact.getSecret() << std::endl;
}

PhoneBook::PhoneBook() : nb_contact(0), index(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
    str firstName;
    str lasteName;
    str nickname;
    str phoneNumber;
    str secret;
    
    ask_question("Enter your first name : ", firstName);
    ask_question("Enter your laste name : ", lasteName);
    ask_question("Enter your nickname : ", nickname);
    ask_question("Enter your phone number : ", phoneNumber);
    ask_question("Enter your darkset secrete : ", secret);

    this->contacts[this->index].setFirstName(firstName);
    this->contacts[this->index].setLasteName(lasteName);
    this->contacts[this->index].setNickname(nickname);
    this->contacts[this->index].setPhoneNumber(phoneNumber);
    this->contacts[this->index].setSecret(secret);

    this->index = (this->index + 1) % 8; // if index + 1 = 8 then index = 0 (0 -> 7 = 8 contacts)
    if (this->nb_contact < 8)
        this->nb_contact++;
}

void PhoneBook::search_contact()
{
    str firstname;
    str lastename;
    str nickname;
    str input;
    int index;

    if(this->nb_contact == 0)
    {
        std::cout << "The number of contact is 0." << std::endl;
        return ;
    }

    std::cout << std::right;
    print_header_tab();

    for(int i = 0; i < this->nb_contact; i++)
    {
        firstname = this->contacts[i].getFirstName();
        lastename = this->contacts[i].getLasteName();
        nickname = this->contacts[i].getNickname();

        firstname = trunc_value(firstname);
        lastename = trunc_value(lastename);
        nickname = trunc_value(nickname);

        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << firstname << "|";
        std::cout << std::setw(10) << lastename << "|";
        std::cout << std::setw(10) << nickname << "|" << std::endl;
    }
    
    std::cout << "Enter the number of index of your contact : ";
    while(!(std::cin >> index))
    {
        std::cout << "Please enter a valid number : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if(index < 0 || index >= this->nb_contact)
    {
        std::cout << "Contact not found" << std::endl;
        std::cout << "Press a key to continue..." << std::endl;
        getchar();
        getchar();
        return ;
    }
    
    print_contact(this->contacts[index]);
    std::cout << "Press a key to continue..." << std::endl;
    getchar();
    getchar();
    return ;
}
