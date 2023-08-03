/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Recursive.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:34:03 by pgros             #+#    #+#             */
/*   Updated: 2023/08/03 15:04:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSIVE_HPP
# define RECURSIVE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Pair.hpp"
#include "PmergeMe.hpp"
#include "binarySearch.hpp"

template <int N>
class Recursive
{
	public:

	/*------------------------------- Vector -------------------------------*/
	template <typename T>
	static void FordJohnsonSort(std::vector<T> &v)
	{
		T *stray = NULL;

		//Stop condition
		if (v.size() < 2 || N < 2)
			return;
			
		// Make pairs (A, B) and identify highest value as A
		std::vector<Pair<T> > u(v.size() / 2);
		if (v.size() % 2) //stores stray value in case of an odd size
			stray = &(*(--v.end()));
		for (unsigned long i = 0; i < u.size(); i++)
		{
			u[i] = Pair<T>(v[2 * i], v[2 * i + 1]); //instantiate pairs
			u[i].sort(); //sort pair (ie: set highest value as A)
		}
		// Sort list of pairs recursively
		Recursive<N - 1>::template FordJohnsonSort<Pair<T> >(u);
		
		// Insert Bs in main chain with binary search
		v = insertPairs(u, stray);
	}

	template <typename T>
	static std::vector<T> insertPairs(std::vector<Pair<T> > &u, T *stray)
	{
		int J_upper = 1;
		int J_lower = 1;
		int tmp = J_lower;
		typename std::vector<T>::iterator pos;
		typename std::vector<T>::iterator last;
		std::vector<T> mainChain;
	
	
		mainChain.push_back(*(u[0].b()));
		mainChain.push_back(*(u[0].a()));
		if (J_upper == static_cast<int>(u.size()) && stray)
		{
			pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
			mainChain.insert(pos, *stray);
		}
		while (J_upper < static_cast<int>(u.size()))
		{
			// set Jacobstahl values
			tmp = J_lower;
			J_lower = J_upper;
			J_upper = std::min(Jacobstahl_n(J_lower, tmp), static_cast<int>(u.size()));

			// First add all As to mainChain
			for (int i = J_lower; i < J_upper; i++)
				mainChain.push_back(*(u[i].a()));

			// Than insert Bs
				// first insert stray if it exists
			if (J_upper == static_cast<int>(u.size()) && stray)
			{
				pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
				mainChain.insert(pos, *stray);
			}
				// than add Bs
			for (int i = J_upper - 1; i >= J_lower; i--)
			{
				if (J_upper == static_cast<int>(u.size()))
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



	/*------------------------------- Deque -------------------------------*/
	template <typename T>
	static void FordJohnsonSort(std::deque<T> &v)
	{
		T *stray = NULL;

		//Stop condition
		if (v.size() < 2 || N < 2)
			return;
			
		// Make pairs (A, B) and identify highest value as A
		std::deque<Pair<T> > u(v.size() / 2);
		if (v.size() % 2) //store stray value in case of an odd size
			stray = &(*(--v.end()));
		for (unsigned long i = 0; i < u.size(); i++)
		{
			u[i] = Pair<T>(v[2 * i], v[2 * i + 1]); //instantiate (A, B) pairs
			u[i].sort(); //sort pair (ie: set highest value as A)
		}
		// Sort list of pairs recursively
		Recursive<N - 1>::template FordJohnsonSort<Pair<T> >(u);
		
		// Insert Bs in main chain with binary search
		v = insertPairs(u, stray);
	}

	template <typename T>
	static std::deque<T> insertPairs(std::deque<Pair<T> > &u, T *stray)
	{
		int J_upper = 1;
		int J_lower = 1;
		int tmp = J_lower;
		typename std::deque<T>::iterator pos;
		typename std::deque<T>::iterator last;
		std::deque<T> mainChain;
	
	
		mainChain.push_back(*(u[0].b()));
		mainChain.push_back(*(u[0].a()));
		if (J_upper == static_cast<int>(u.size()) && stray)
		{
			pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
			mainChain.insert(pos, *stray);
		}
		while (J_upper < static_cast<int>(u.size()))
		{
			// set Jacobstahl values
			tmp = J_lower;
			J_lower = J_upper;
			J_upper = std::min(Jacobstahl_n(J_lower, tmp), static_cast<int>(u.size()));

			// First add all As to mainChain
			for (int i = J_lower; i < J_upper; i++)
				mainChain.push_back(*(u[i].a()));

			// Than insert Bs
				// first insert stray if it exists
			if (J_upper == static_cast<int>(u.size()) && stray)
			{
				pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
				mainChain.insert(pos, *stray);
			}
				// than add all Bs
			for (int i = J_upper - 1; i >= J_lower; i--)
			{
				if (J_upper == static_cast<int>(u.size()))
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