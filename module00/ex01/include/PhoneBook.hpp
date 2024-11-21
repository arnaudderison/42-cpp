/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:34:34 by aderison          #+#    #+#             */
/*   Updated: 2024/11/21 16:28:33 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Repertory.hpp"

class PhoneBook
{
    private:
        int nb_contact;
        int index;
        Contact contacts[8];

    public:
        PhoneBook();
        ~PhoneBook();

        void add_contact();
        void search_contact();
};
