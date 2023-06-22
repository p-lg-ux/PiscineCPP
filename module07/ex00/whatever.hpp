/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:54:26 by pgros             #+#    #+#             */
/*   Updated: 2023/06/22 18:56:53 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &x, T &y)
{
	T tmp = x;

	x = y;
	y = tmp;
}

template<typename T>
T const &	max(T const &x, T const &y)
{
	return ( x > y ? x : y);
}

template<typename T>
T const &	min(T const &x, T const &y)
{
	return ( x < y ? x : y);
}

#endif