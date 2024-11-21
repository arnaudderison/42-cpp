/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:15:18 by aderison          #+#    #+#             */
/*   Updated: 2024/11/20 01:06:11 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Repertory.hpp"

// Constructeur
Contact::Contact()
{
}

// Destructeur
Contact::~Contact()
{
}

// Getter
str Contact::getFirstName() const
{
    return this->firstName;
}

str Contact::getLasteName() const
{
    return this->lasteName;
}

str Contact::getNickname() const
{
    return this->nickname;
}

str Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

str Contact::getSecret() const
{
    return this->secret;
}

// Setter
void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLasteName(std::string lasteName)
{
    this->lasteName = lasteName;
}

void Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setSecret(std::string secret)
{
    this->secret = secret;
}
