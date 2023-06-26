/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:21:26 by pgros             #+#    #+#             */
/*   Updated: 2023/06/26 09:28:10 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <string>
# include <algorithm>

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