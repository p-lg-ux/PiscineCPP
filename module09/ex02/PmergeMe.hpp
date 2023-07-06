/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:20 by pgros             #+#    #+#             */
/*   Updated: 2023/07/06 17:37:03 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
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
};
#endif