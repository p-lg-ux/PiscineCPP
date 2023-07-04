/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:41:04 by pgros             #+#    #+#             */
/*   Updated: 2023/07/04 09:41:16 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
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