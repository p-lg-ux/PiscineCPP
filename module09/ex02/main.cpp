/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:18:31 by pgros             #+#    #+#             */
/*   Updated: 2023/07/06 19:05:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Recursive.hpp"

// constexpr int getSize(std::vector<int> &v)
// {
//    return v.size();
// }

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
		// const int SIZE_ = getSize(p.vect);
		Recursive<512>::FordJohnsonSort<int>(p.vect);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}