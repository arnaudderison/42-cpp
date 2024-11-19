/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:04:50 by aderison          #+#    #+#             */
/*   Updated: 2024/11/19 20:38:04 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma CONTACT_H

#include "repertory.hpp"

class Contact {
    private:
        str firstName;
        str lasteName;
        str nickname;
        str phoneNumber;
        str secret;
        
    public:
        // constructeur/destructeur
        Contact();
        ~Contact();
        
        // Getter
        str getFirstName();
        str getLasteName();
        str getNickname();
        str getPhoneNumber();
        str getSecret();

        //Setter
        void setFirstName(str firstName);
        void setLasteName(str lasteName);
        void setNickname(str nickname);
        void setPhoneNumber(str phoneNumber);
        void setSecret(str secret);   
}
