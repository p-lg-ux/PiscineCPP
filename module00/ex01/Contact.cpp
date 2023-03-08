/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:23:31 by pgros             #+#    #+#             */
/*   Updated: 2023/03/07 18:25:34 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Contact::Contact()
{
	std::cout << "Default constructor of Contact called." << std::endl;
}
// Contact::Contact(const Contact& other)
// {
// (void)other;
// 	//std::cout << "Copy constructor of Contact called." << std::endl;
// }

Contact::~Contact()
{
	std::cout << "Destructor of Contact called." << std::endl;
}
//overloads
// Contact& Contact::operator=(const Contact& rhs)
// {
// (void)rhs;
// 	return *this;
// }