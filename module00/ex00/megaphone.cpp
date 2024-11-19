/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:02:31 by aderison          #+#    #+#             */
/*   Updated: 2024/11/19 20:02:48 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

void megaphone(int argc, char* argv[])
{
    int len = 0;
    int i = 0;

    while(++i < argc)
    {
        len = strlen(argv[i]);

        for(int j = 0; j < len; j++)
            std::cout << (char)toupper(argv[i][j]);
    }
}

int main(int argc, char* argv[])
{
    if(argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        megaphone(argc, argv);

    return 0;
}
