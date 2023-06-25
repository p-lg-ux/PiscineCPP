/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:21:26 by pgros             #+#    #+#             */
/*   Updated: 2023/06/25 21:14:13 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <string>
# include <algorithm>

// class NoOccurenceException : public std::exception
// {
// 	virtual const char* what() const throw()
// 	{
// 		return ("No occurence found.");
// 	};
// };

template<typename T>
int& easyfind(T &contain, int n)
{
	typename T::iterator it = std::find(contain.begin(), contain.end(), n);
	if (it != contain.end())
		return(*it);
	else
		throw std::exception();
}

#endif