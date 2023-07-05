/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:20 by pgros             #+#    #+#             */
/*   Updated: 2023/07/05 21:36:25 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include "Pair.hpp"
# include <iostream>
# include <string>
# include <vector>

template<typename T>
void printContainer(T& c)
{
	typename T::iterator it = c.begin();

	std::cout << "{ ";
	for (;it != c.end(); it++)
			std::cout << *it << ", ";
	std::cout << "}";
}

class PmergeMe
{
	public:
	std::vector<int> vect;
	//constructors and destructors
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	//overloads
	PmergeMe& operator=(const PmergeMe& rhs);

	//other member functions
	void storeInput(int ac, char **av);
	
	class ErrorException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	template<typename T, int N>
	void FordJohnsonSort(std::vector<T> &v)
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
		FordJohnsonSort<Pair<T>, (int)(u.size()) >(u);
	
		//insert bs in main chain with binary search
	}
	
	template<typename T>
	void FordJohnsonSort<T,1>(std::vector<T> &v)
	{
		(void)v;
		return;
	}

	template<typename T>
	void FordJohnsonSort<T,0>(std::vector<T> &v)
	{
		(void)v;
		return;
	}
};
#endif