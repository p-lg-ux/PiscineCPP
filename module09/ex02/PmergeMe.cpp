/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:41:04 by pgros             #+#    #+#             */
/*   Updated: 2023/08/02 14:00:15 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <string>

//constructors and destructors
PmergeMe::PmergeMe()
{
	//std::cout << "Default constructor of PmergeMe called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
(void)other;
	//std::cout << "Copy constructor of PmergeMe called." << std::endl;
}

PmergeMe::~PmergeMe()
{
	//std::cout << "Destructor of PmergeMe called." << std::endl;
}

//overloads
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	(void)rhs;
	return *this;
}

void PmergeMe::storeInput(int ac, char **av)
{
	int	val;
	std::stringstream	iss;

	for (int i=1; i<ac; i++)
	{
		for (int j=0; av[i][j]!='\0'; j++)
		{
			if (!std::isdigit(av[i][j]) )
				throw ErrorException();
		}
		iss.clear();
		iss << av[i];
		iss >> val;
		if (iss.fail())
			throw ErrorException();
		vect.push_back(val);
		deq.push_back(val);
	}
}

const char* PmergeMe::ErrorException::what() const throw()
{
	return ("Error");
}

