/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:25:52 by pgros             #+#    #+#             */
/*   Updated: 2023/03/09 19:59:06 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

//constructors and destructors
PhoneBook::PhoneBook()
{
	// std::cout << "Default constructor of PhoneBook called." << std::endl;
	this->_nb_of_contacts = 0;
}
// PhoneBook::PhoneBook(const PhoneBook& other)
// {
// (void)other;
// 	//std::cout << "Copy constructor of PhoneBook called." << std::endl;
// }
PhoneBook::~PhoneBook()
{
	// std::cout << "Destructor of PhoneBook called." << std::endl;
}

void	PhoneBook::addContact(void)
{
	int	i = 0;

	if (this->_nb_of_contacts >= 8)
	{
		while (i < 7)
		{
			this->_contacts_tab[i] = this->_contacts_tab[i + 1];
			i++;
		}
		this->_contacts_tab[7].setAttributes();
	}
	else
	{
		this->_contacts_tab[this->_nb_of_contacts].setAttributes();
		this->_nb_of_contacts++;
	}
}

void	PhoneBook::displayAll(void)
{
	int	i = 0;

	std::cout << std::endl << BOLD << LINE << std::endl << "|";
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << "nickname";
	std::cout << "|" << std::endl << LINE << RESET << std::endl;
	while (i < this->_nb_of_contacts)
	{
		this->_contacts_tab[i].displayShort(i);
		i++;	
	}
	std::cout << BOLD << LINE << RESET << std::endl;
}

void	PhoneBook::search(void)
{
	std::string	str;

	this->displayAll();
	while (1)
	{
		std::cout << std::endl << YELLOW_B << "Enter a contact index > " << RESET;
		std::cin >> str;
		if (str.length() != 1)
		{
			std::cout << RED_B << "Invalid input" << RESET << std::endl;
			continue ;
		}
		if (str >= "0" && str <= "8")
			break;
		else
			std::cout << RED_B << "Invalid input" << RESET << std::endl;
	}
	this->_contacts_tab[str[0] - '0'].displayFull();
	
}
//overloads
// PhoneBook& PhoneBook::operator=(const PhoneBook& rhs)
// {
// (void)rhs;
// 	return *this;
// }
