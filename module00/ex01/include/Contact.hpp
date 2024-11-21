/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:04:50 by aderison          #+#    #+#             */
/*   Updated: 2024/11/20 01:05:48 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Repertory.hpp"

class Contact {
    private:
        std::string firstName;
        std::string lasteName;
        std::string nickname;
        std::string phoneNumber;
        std::string secret;
        
    public:
        // constructeur/destructeur
        Contact();
        ~Contact();
        
        // Getter
        std::string getFirstName() const;
        std::string getLasteName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getSecret() const;

        //Setter
        void setFirstName(std::string firstName);
        void setLasteName(std::string lasteName);
        void setNickname(std::string nickname);
        void setPhoneNumber(std::string phoneNumber);
        void setSecret(std::string secret);   
};
