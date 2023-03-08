/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:23:32 by pgros             #+#    #+#             */
/*   Updated: 2023/03/07 13:59:56 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

# define DEFAULT_MSG	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int ac, char *av[])
{
	std::string				str;
	std::string::size_type 	j = 0;
	int						i = 1;

	if (ac == 1)
	{
		std::cout << DEFAULT_MSG << std::endl;
		return (0);
	}
	while (i < ac)
	{
		str = av[i];
		j = 0;
		while (j < str.length())
		{
			std::cout << (char)std::toupper(str[j]) ;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
