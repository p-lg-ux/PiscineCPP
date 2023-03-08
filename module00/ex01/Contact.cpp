/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:23:31 by pgros             #+#    #+#             */
/*   Updated: 2023/03/08 19:49:05 by pgros            ###   ########.fr       */
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

/*	setters	*/
void	Contact::setFirstName(std::string str)
{
	this->_first_name = str;
	return ;
}

void	Contact::setLastName(std::string str)
{
	this->_last_name = str;
	return ;
}

void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
	return ;
}

void	Contact::setPhoneNumber(std::string str)
{
	this->_phone_nb = str;
	return ;
}

void	Contact::setSecret(std::string str)
{
	this->_secret = str;
	return ;
}

/*	getters	*/
std::string	Contact::getFirstName(void)
{
	return (this->_first_name);
}

std::string	Contact::getLastName(void)
{
	return (this->_last_name);
}

std::string	Contact::getNickname(void)
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phone_nb);
}
std::string	Contact::getSecret(void)
{
	return (this->_secret);
}
