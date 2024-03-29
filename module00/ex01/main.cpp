/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:27:15 by pgros             #+#    #+#             */
/*   Updated: 2023/03/23 18:08:15 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	command;
	
	while (1)
	{
		std::cout << std::endl << YELLOW_B << "Enter a command (ADD, SEARCH or EXIT):" << RESET << std::endl << "> " ;
		if (std::getline(std::cin, command))
		{
			if (command == "EXIT")
				break;
			else if (command == "SEARCH")
				book.search();
			else if (command == "ADD")
				book.addContact();
			else
				std::cerr << ERR_INPUT << std::endl;
		}
		else
		{
			std::cerr << std::endl << ERR_INPUT << std::endl;
			std::cin.clear();
			std::cin.unget();
			if (std::cin.peek() == EOF)
				return (1);
			std::cin.ignore();
		}
	}
	return (0);
}