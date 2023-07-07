/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Recursive.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:34:03 by pgros             #+#    #+#             */
/*   Updated: 2023/07/07 18:43:57 by pgros            ###   ########.fr       */
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
		std::cout << "------ recursive " << 128 - N << " ------" << std::endl;
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
		v = insertPairs(v, u, stray);
		std::cout << "vector v = ";
		printContainer(v);
		std::cout << std::endl;
	}

	template<typename T>
	static std::vector<T> insertPairs(std::vector<T> &v, std::vector<Pair<T> > &u, T* stray)
	{
		(void)v;
		std::cout << "------ insert " << 128 - N << " ------" << std::endl;
		unsigned long	J_upper = 1;
		unsigned long	J_lower = 1;
		unsigned long	tmp = J_lower;
		std::vector<T> mainChain;
		std::cout << "mainChain = ";
		printContainer(mainChain);
		std::cout << std::endl;
		mainChain.push_back(*(u[0].b()));
		mainChain.push_back(*(u[0].a()));
		std::cout << "mainChain = ";
		printContainer(mainChain);
		std::cout << std::endl;
		while (J_upper < u.size())
		{
			tmp = J_lower;
			J_lower = J_upper;
			J_upper = std::min(Jacobstahl_n(J_lower, tmp), static_cast<int>(u.size()));
			// add all as to mainChain
			for(unsigned long i=J_lower; i<J_upper; i++)
				mainChain.push_back(*(u[i].a()));
			// insert bs
			//TODO: insert stray and verify 
			if (J_upper == u.size() && stray)
				pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
				//TODO: insert stray at pos in mainChain
			for (int i=J_upper-1;i>=J_lower;i--)
			{
				std::vector<T>::iterator last;
				if (J_upper == u.size())
					last = mainChain.end();
				else
					last = mainChain.begin() + J_upper + J_lower - 1;
				//binary search in a list of size (2^n)-1 = t_n + t_n-1 - 1 where t_n = Jacobstahl_n
				//TODO: formula not valid when J_upper == u.size()
				pos = binary_search(mainChain.begin(), last, *(u[i].b()));
				//TODO: insert *(u[i].b()) at pos in mainChain
			}
		}
		return (mainChain);
	}
	
	static int Jacobstahl_n(int Jacobstahl_n_1, int Jacobstahl_n_2)
	{
		//Jacobsthal suite : t_n = t_n-1 + 2*t_n-2
		return (Jacobstahl_n_1 + 2 * Jacobstahl_n_2); 
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

	template<typename T>
	static std::vector<T> insertPairs(std::vector<T> &v, std::vector<Pair<T> > &u, T* stray)
	{
		(void)v;
		(void)u;
		(void)stray;
		return;
	}
};

// template<>
// class Recursive<0>{
	
// 	public:
// 	template<typename T>
// 	static void FordJohnsonSort(std::vector<T> &v)
// 	{
// 		(void)v;
// 		return;
// 	}
// };

#endif