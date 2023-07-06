/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Recursive.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:34:03 by pgros             #+#    #+#             */
/*   Updated: 2023/07/06 19:06:27 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSIVE_HPP
# define RECURSIVE_HPP
# include <iostream>
# include <string>
# include <vector>
# include "Pair.hpp"
# include "PmergeMe.hpp"


template<int N>
class Recursive{

	public:
	template<typename T>
	static void FordJohnsonSort(std::vector<T> &v)
	{
		T *stray = NULL;
		
		//make pairs and identify highest value
		if (v.size() < 2 || N < 2)
			return;
		std::vector< Pair<T> > u(v.size() / 2);
		if (v.size() % 2)
		{
			stray = &(*(--v.end()));
			std::cout << "stray = " << *stray << std::endl;
		}
		for (unsigned long i=0; i < u.size(); i++)
		{
			u[i] = Pair<T>(v[2*i], v[2*i + 1]);
			u[i].sort();
		}
		std::cout << "Pair vector u = ";
		printContainer(u);
		std::cout << std::endl;
		//sort pairs recursively
		Recursive<N - 1>::template FordJohnsonSort<Pair<T> >(u);
		//insert bs in main chain with binary search
		
	}
};

template<>
class Recursive<1>{
	
	public:
	template<typename T>
	static void FordJohnsonSort(std::vector<T> &v)
	{
		(void)v;
		return;
	}
};

template<>
class Recursive<0>{
	
	public:
	template<typename T>
	static void FordJohnsonSort(std::vector<T> &v)
	{
		(void)v;
		return;
	}
};

#endif