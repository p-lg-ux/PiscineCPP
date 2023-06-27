/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:21:12 by pgros             #+#    #+#             */
/*   Updated: 2023/06/27 17:46:21 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include "Span.hpp"
# define BOLD	"\033[1;39m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define RESET	"\033[0m"
# define RANGE	1000

int	randGenerate()
{
	return(std::rand() % RANGE);
}

int main(void)
{
	std::list<int> myList(100);
	
	// printContainer(myList);
	std::srand(std::time(0));
	std::generate(myList.begin(), myList.end(), randGenerate);
	// printContainer(myList);
	// std::generate(myVector.begin(), myVector.end(), randGenerate);
	// printContainer(myVector);
	Span s(100);
	// s.addNumber(-1);
	// s.addNumber(-3);
	// s.addNumber(-2);
	// s.addNumber(-10);
	// s.addNumber(-50);
	// std::cout << "s = " << s << std::endl;
	s.addMultipleNumber(myList.begin(), myList.end());
	std::cout << "s = " << s << std::endl;
	std::cout << "longestSpan = " << s.longestSpan() << std::endl;
	std::cout << "shortestSpan = " << s.shortestSpan() << std::endl;
	return (0);
}