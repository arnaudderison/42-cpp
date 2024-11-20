/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:02:31 by aderison          #+#    #+#             */
/*   Updated: 2024/11/20 04:02:14 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void megaphone(int argc, char* argv[])
{
    int i = 0;
    std::string word;

    while(++i < argc)
    {
        word = argv[i];
        for(std::string::size_type j = 0; j < word.size(); ++j)
            std::cout << static_cast<char>(toupper(word[j]));
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
