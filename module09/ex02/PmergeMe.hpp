/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:20 by pgros             #+#    #+#             */
/*   Updated: 2023/08/02 14:14:52 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
	std::vector<int> vect;
	std::deque<int> deq;
	
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

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c)
{
	typename std::vector<T>::const_iterator it = c.begin();

	for (int i = 0 ;it != c.end() && i < 100 ; it++)
	{
		os << *it << " ";
		i++;
	}
	if (it != c.end())
		os << "[...]";
	return (os);
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& c)
{
	typename std::deque<T>::const_iterator it = c.begin();

	for (int i = 0 ;it != c.end() && i < 100 ; it++)
	{
		os << *it << " ";
		i++;
	}
	if (it != c.end())
		os << "[...]";
	return (os);
}

#endif