/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:15:18 by aderison          #+#    #+#             */
/*   Updated: 2024/11/19 21:29:27 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

// Constructeur
Contact::Contact()
{
}

// Destructeur
Contact::~Contact()
{
}

// Getter
str Contact::getFirstName()
{
    return this->firstName;
}

str Contact::getLasteName()
{
    return this->lasteName;
}

str Contact::getNickname()
{
    return this->nickname;
}

str Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

str Contact::getSecret()
{
    return this->secret;
}

// Setter
void Contact::setFirstName(str firstName)
{
    this->firstName = firstName;
}

void Contact::setLasteName(str lasteName)
{
    this->lasteName = lasteName;
}

void Contact::setNickname(str nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(str phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setSecret(str secret)
{
    this->secret = secret;
}
