/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:23:31 by pgros             #+#    #+#             */
/*   Updated: 2023/03/10 19:16:25 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Contact::Contact()
{
	// std::cout << "Default constructor of Contact called." << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Destructor of Contact called." << std::endl;
}

std::string	Contact::read_input(std::string prompt)
{
	std::string	str = "";

	while (1)
	{
		std::cout << YELLOW_B << prompt << RESET;
		std::cin.clear();
		std::cin.unget();
		std::cin.ignore();
		if (std::getline(std::cin, str))
		{
			if (str.empty())
				std::cout << std::endl << ERR_EMPTY << std::endl;
			else
				break ;
		}
		else
		{
			std::cout << std::endl << ERR_INPUT << std::endl;
			std::cin.clear();
			std::cin.unget();
			std::cin.ignore();
		}
	}
	return (str);
}


void	Contact::setAttributes(void)
{
	std::cout << YELLOW_B << "Please, enter contact infos:" << RESET << std::endl ;
	this->_first_name = read_input("first name > ");
	this->_last_name = read_input("last name > ");
	this->_nickname = read_input("nickname > ");
	this->_phone_nb = read_input("phone number > ");
	this->_secret = read_input("darkest secret > ");
	
}

void	Contact::displayFull(void)
{
	std::cout << BOLD << "first name: " << RESET << _first_name << std::endl;
	std::cout << BOLD << "last name: " << RESET << _last_name << std::endl;
	std::cout << BOLD << "nickname: " << RESET << _nickname << std::endl;
	std::cout << BOLD << "phone number: " << RESET << _phone_nb << std::endl;
	std::cout << BOLD << "darkest secret: " << RESET << _secret << std::endl;
}

void	Contact::displayShort(int index)
{
	std::cout << BOLD << "|" << RESET;
	std::cout << std::setw(10) << index;
	std::cout << BOLD << "|" << RESET;
	std::cout << std::setw(10) << this->_first_name;
	std::cout << BOLD << "|" << RESET;
	std::cout << std::setw(10) << this->_last_name;
	std::cout << BOLD << "|" << RESET;
	std::cout << std::setw(10) << this->_nickname;
	std::cout << BOLD << "|" << RESET << std::endl;
}


