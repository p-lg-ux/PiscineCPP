/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:18:31 by pgros             #+#    #+#             */
/*   Updated: 2023/07/07 14:42:31 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Recursive.hpp"

int main(int ac, char **av)
{
	PmergeMe	p;

	try {
		if (ac == 1)
			throw PmergeMe::ErrorException();
		p.storeInput(ac, av);
		std::cout << "vector = ";
		printContainer<std::vector<int> >(p.vect);
		std::cout << std::endl;
		Recursive<128>::FordJohnsonSort<int>(p.vect);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}