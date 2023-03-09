/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:27:15 by pgros             #+#    #+#             */
/*   Updated: 2023/03/09 19:23:25 by pgros            ###   ########.fr       */
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
		std::cin >> command;
		if (command == "EXIT")
			break;
		else if (command == "SEARCH")
			book.search();
		else if (command == "ADD")
			book.addContact();
		else
			std::cout << RED_B << "Invalid command" << RESET << std::endl;
	}
	return (0);
}