/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:37:55 by pgros             #+#    #+#             */
/*   Updated: 2023/06/22 19:02:22 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
# define BOLD	"\033[1;39m"
# define RESET	"\033[0m"

int main(void)
{
	std::cout << std::endl << BOLD << "Tests with int" << RESET << std::endl;
	{
		int	tab[] = {0,1,2,3,4,5,6,7,8,9};
		::iter(tab, 10, &print<int>);
		::iter(tab, 10, &increment<int>);
		std::cout << "increment" << std::endl;
		::iter(tab, 10, &print<int>);
	}

	std::cout << std::endl << BOLD << "Tests with std::string" << RESET << std::endl;
	{
		std::string	tab[] = {"Hello", "World", "String"};
		::iter(tab, 3, &print<std::string>);
	}

	return (0);
}