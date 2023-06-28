/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:21:12 by pgros             #+#    #+#             */
/*   Updated: 2023/06/28 13:15:39 by pgros            ###   ########.fr       */
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
# define RANGE	2147483647

int	randGenerate()
{
	return(std::rand() % RANGE - RANGE/2);
}

int main(void)
{
	int	n = 100000;
	std::list<int> myList(n);
	std::srand(std::time(0));
	std::generate(myList.begin(), myList.end(), randGenerate);

	std::cout << BOLD << "Tests on short list of size 5" << RESET << std::endl;
	{
		Span s(5);
		
		try {s.addMultipleNumber(myList.begin(), myList.end());}
		catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}

		try {s.longestSpan();}
		catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}

		s.addNumber(-1);
		try {s.shortestSpan();}
		catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}
		
		s.addNumber(3);
		s.addNumber(-2);
		s.addNumber(10);
		s.addNumber(-50);
		
		try {s.addNumber(17);}
		catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}

		std::cout << "s = " << s << std::endl;
		std::cout << "longestSpan = " << s.longestSpan() << std::endl;
		std::cout << "shortestSpan = " << s.shortestSpan() << std::endl;
	}
	
	std::cout << std::endl << BOLD << "Tests on long list of size " << n << RESET << std::endl;
	{
		Span s(n);
		
		s.addMultipleNumber(myList.begin(), myList.end());
		if (s.get_L().size() <= 500)
			std::cout << "s = " << s << std::endl;
		std::cout << "longestSpan = " << s.longestSpan() << std::endl;
		std::cout << "shortestSpan = " << s.shortestSpan() << std::endl;
	}
	
	return (0);
}