/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Recursive.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:34:03 by pgros             #+#    #+#             */
/*   Updated: 2023/08/02 17:10:52 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSIVE_HPP
#define RECURSIVE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Pair.hpp"
#include "PmergeMe.hpp"

static int call = 0;

template <typename T>
static typename std::vector<T>::iterator binary_search(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T &val)
{
	typename std::vector<T>::iterator middle;
	call += 1;

	// Stop condition
	if (std::distance(first, last) < 2)
	{
		if (val < *first)
			return (first);
		else
			return (last);
	}
	// Else
	middle = first + std::distance(first, last) / 2;
	if (val < *middle) 
		return (binary_search(first, middle, val)); // calls binary_search on left part
	else 
		return (binary_search(middle, last, val)); // calls binary_search on right part
}

template <typename T>
static typename std::deque<T>::iterator binary_search(typename std::deque<T>::iterator first, typename std::deque<T>::iterator last, T &val)
{
	typename std::deque<T>::iterator middle;
	call += 1;

	// Stop condition
	if (std::distance(first, last) < 2)
	{
		if (val < *first)
			return (first);
		else
			return (last);
	}
	// Else
	middle = first + std::distance(first, last) / 2;
	if (val < *middle) 
		return (binary_search(first, middle, val)); // calls binary_search on left part
	else 
		return (binary_search(middle, last, val)); // calls binary_search on right part
}


template <int N>
class Recursive
{

public:
	template <typename T>
	static void FordJohnsonSort(std::vector<T> &v)
	{
		T *stray = NULL;

		//Stop condition
		if (v.size() < 2 || N < 2)
			return;
			
		// Make pairs and identify highest value
		std::vector<Pair<T> > u(v.size() / 2);
		if (v.size() % 2) //stores stray value in case of an odd size
			stray = &(*(--v.end()));
		for (unsigned long i = 0; i < u.size(); i++)
		{
			u[i] = Pair<T>(v[2 * i], v[2 * i + 1]); //instantiate pairs
			u[i].sort(); //sort pairs
		}
		// Sort pairs recursively
		Recursive<N - 1>::template FordJohnsonSort<Pair<T> >(u);
		
		// Insert bs in main chain with binary search
		v = insertPairs(u, stray);
	}

	template <typename T>
	static std::vector<T> insertPairs(std::vector<Pair<T> > &u, T *stray)
	{
		unsigned long J_upper = 1;
		unsigned long J_lower = 1;
		unsigned long tmp = J_lower;
		typename std::vector<T>::iterator pos;
		typename std::vector<T>::iterator last;
		std::vector<T> mainChain;
	
	
		mainChain.push_back(*(u[0].b()));
		mainChain.push_back(*(u[0].a()));
		if (J_upper == u.size() && stray)
		{
			pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
			mainChain.insert(pos, *stray);
		}
		while (J_upper < u.size())
		{
			// std::cout << "J_upper = " << J_upper << std::endl;
			// set Jacobstahl values
			tmp = J_lower;
			J_lower = J_upper;
			J_upper = std::min(Jacobstahl_n(J_lower, tmp), static_cast<int>(u.size()));

			// add all as to mainChain
			for (unsigned long i = J_lower; i < J_upper; i++)
				mainChain.push_back(*(u[i].a()));

			// insert bs
			// first insert stray if it exists
			if (J_upper == u.size() && stray)
			{
				pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
				mainChain.insert(pos, *stray);
			}
			// than add 
			for (unsigned long i = J_upper - 1; i >= J_lower; i--)
			{
				if (J_upper == u.size())
					last = mainChain.end();
				else
					last = mainChain.begin() + J_upper + J_lower - 1;
				// binary search in a list of size (2^n)-1 = t_n + t_n-1 - 1 where t_n = Jacobstahl_n
				pos = binary_search(mainChain.begin(), last, *(u[i].b()));
				mainChain.insert(pos, *(u[i].b()));
			}
		}
		return (mainChain);
	}


	template <typename T>
	static void FordJohnsonSort(std::deque<T> &v)
	{
		T *stray = NULL;

		//Stop condition
		if (v.size() < 2 || N < 2)
			return;
			
		// Make pairs and identify highest value
		std::deque<Pair<T> > u(v.size() / 2);
		if (v.size() % 2) //stores stray value in case of an odd size
			stray = &(*(--v.end()));
		for (unsigned long i = 0; i < u.size(); i++)
		{
			u[i] = Pair<T>(v[2 * i], v[2 * i + 1]); //instantiate pairs
			u[i].sort(); //sort pairs
		}
		// Sort pairs recursively
		Recursive<N - 1>::template FordJohnsonSort<Pair<T> >(u);
		
		// Insert bs in main chain with binary search
		v = insertPairs(u, stray);
	}

	template <typename T>
	static std::deque<T> insertPairs(std::deque<Pair<T> > &u, T *stray)
	{
		unsigned long J_upper = 1;
		unsigned long J_lower = 1;
		unsigned long tmp = J_lower;
		typename std::deque<T>::iterator pos;
		typename std::deque<T>::iterator last;
		std::deque<T> mainChain;
	
	
		mainChain.push_back(*(u[0].b()));
		mainChain.push_back(*(u[0].a()));
		if (J_upper == u.size() && stray)
		{
			pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
			mainChain.insert(pos, *stray);
		}
		while (J_upper < u.size())
		{
			// std::cout << "J_upper = " << J_upper << std::endl;
			// set Jacobstahl values
			tmp = J_lower;
			J_lower = J_upper;
			J_upper = std::min(Jacobstahl_n(J_lower, tmp), static_cast<int>(u.size()));

			// add all as to mainChain
			for (unsigned long i = J_lower; i < J_upper; i++)
				mainChain.push_back(*(u[i].a()));

			// insert bs
			// first insert stray if it exists
			if (J_upper == u.size() && stray)
			{
				pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
				mainChain.insert(pos, *stray);
			}
			// than add 
			for (unsigned long i = J_upper - 1; i >= J_lower; i--)
			{
				if (J_upper == u.size())
					last = mainChain.end();
				else
					last = mainChain.begin() + J_upper + J_lower - 1;
				// binary search in a list of size (2^n)-1 = t_n + t_n-1 - 1 where t_n = Jacobstahl_n
				pos = binary_search(mainChain.begin(), last, *(u[i].b()));
				mainChain.insert(pos, *(u[i].b()));
			}
		}
		return (mainChain);
	}

	static int Jacobstahl_n(int Jacobstahl_n_1, int Jacobstahl_n_2)
	{
		// Jacobsthal suite : t_n = t_n-1 + 2*t_n-2
		return (Jacobstahl_n_1 + 2 * Jacobstahl_n_2);
	}

};

template <>
class Recursive<1>
{

public:
	template <typename T>
	static void FordJohnsonSort(std::vector<T> &v)
	{
		(void)v;
		return;
	}

	template <typename T>
	static void FordJohnsonSort(std::deque<T> &v)
	{
		(void)v;
		return;
	}
};


#endif