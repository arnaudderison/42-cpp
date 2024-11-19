/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:34:34 by aderison          #+#    #+#             */
/*   Updated: 2024/11/19 21:44:20 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma REPERTORY_H

#include "repertory.hpp"

class PhoneBook
{
    private:
        const int max_contact;
        int nb_contact;
        int index;
        Contact contacts[8];

    public:
        PhoneBook();
        ~PhoneBook();
}
