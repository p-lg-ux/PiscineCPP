/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:27:15 by pgros             #+#    #+#             */
/*   Updated: 2023/03/08 20:31:34 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	add_command(void)
{
	std::string str[5];
	int			i = 0;

	
}

int main(void)
{
	PhoneBook	book;
	std::string	command;
	
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT):" << std::endl << "> " ;
		std::cin >> command;
		if (command == "EXIT")
			break;
		// else if (command == "SEARCH")
		// else if (command == "ADD")
		else
			std::cout << "Invalid command" << std::endl;
	}
	
	return (0);
}