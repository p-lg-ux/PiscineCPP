/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:25:52 by pgros             #+#    #+#             */
/*   Updated: 2023/03/08 16:31:33 by pgros            ###   ########.fr       */
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
//overloads
// PhoneBook& PhoneBook::operator=(const PhoneBook& rhs)
// {
// (void)rhs;
// 	return *this;
// }
