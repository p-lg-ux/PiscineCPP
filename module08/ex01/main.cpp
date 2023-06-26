/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:21:12 by pgros             #+#    #+#             */
/*   Updated: 2023/06/26 16:28:07 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "Span.hpp"
# define BOLD	"\033[1;39m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define RESET	"\033[0m"

int main(void)
{
	int array[4] = { 0, 5, 6, 7 };
	int* itbegin = array + 0;
	int* itend   = array + 4;
	
	Span s(10);
	// s.addNumber(-1);
	// s.addNumber(-3);
	// s.addNumber(-2);
	// s.addNumber(-10);
	// s.addNumber(-50);
	s.addNumber(itbegin, itend);
	std::cout << "s = " << s << std::endl;
	std::cout << "longestSpan = " << s.longestSpan() << std::endl;
	std::cout << "shortestSpan = " << s.shortestSpan() << std::endl;
	return (0);
}