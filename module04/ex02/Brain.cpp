/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:49:52 by pgros             #+#    #+#             */
/*   Updated: 2023/05/08 17:28:46 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Brain::Brain()
{
	std::cout << "Default constructor of Brain called." << std::endl;
}
Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Copy constructor of Brain called." << std::endl;
}
Brain::~Brain()
{
	std::cout << "Destructor of Brain called." << std::endl;
}
//overloads
Brain& Brain::operator=(const Brain& rhs)
{
	for (int i = 0; i<100; i++)
		ideas[i] = rhs.getIdea(i);
	return *this;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("");
	return (ideas[i]);
}

void Brain::setIdea(std::string idea)
{
	int i=0;
	
	while (i < 100)
	{
		if (ideas[i].empty())
		{
			ideas[i] = idea;
			break;
		}
		i++;
	}
}

