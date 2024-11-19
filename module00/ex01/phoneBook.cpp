/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:44:20 by aderison          #+#    #+#             */
/*   Updated: 2024/11/19 22:00:17 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

static void ask_question(str& question, str& input)
{   
    system("clear");
    std::cout << question;
    std::getline(std::cin, input);
}

PhoneBook::PhoneBook() : max_contact(8), nb_contact(0), index(0)
{
}

PhoneBook::~PhoneBook()
{
}

PhoneBook::add_contact()
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
    this->contacts[this->index].setLastName(lastName);
    this->contacts[this->index].setNickname(nickname);
    this->contacts[this->index].setPhoneNumber(phoneNumber);
    this->contacts[this->index].setSecret(secret);

    this->index = (this.index + 1) % 8; // if index + 1 = 8 then index = 0 (0 -> 7 = 8 contacts)
    if (this->nb_contact < 8)
        this->nb_contact++;
}
