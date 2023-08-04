/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:18:31 by pgros             #+#    #+#             */
/*   Updated: 2023/08/04 13:27:41 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Recursive.hpp"
#include <ctime>
#include <sys/time.h>

extern int call;

void	printDuration(std::clock_t time, std::string container, unsigned long range)
{
	std::cout << "Time to process a range of " << range << " elements ";
	std::cout << "with std::" << container << " : ";
	std::cout << ((double) time / (CLOCKS_PER_SEC / 1000000) ) << " us" << std::endl;
}

int main(int ac, char **av)
{
	PmergeMe	p;
	std::clock_t		time;

	try {
		if (ac == 1)
			throw PmergeMe::ErrorException();
		p.storeInput(ac, av);
		std::cout << "Before:\t" << p.vect << std::endl;
		
		time = clock();
		Recursive<32>::FordJohnsonSort<int>(p.vect);
		time = clock() - time;
		std::cout << "After:\t" << p.vect << std::endl;
		printDuration(time, "vector", p.vect.size());
		time = clock();
		Recursive<32>::FordJohnsonSort<int>(p.deq);
		time = clock() - time;
		printDuration(time, "deque", p.deq.size());

	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}
