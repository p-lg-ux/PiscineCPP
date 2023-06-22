/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:28:05 by pgros             #+#    #+#             */
/*   Updated: 2023/06/22 19:00:44 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T>
void iter(T* tab, int size, void (*f)(T&))
{
	if (tab == NULL || f == NULL)
		return;
	for (int i=0;i<size;i++)
		f(tab[i]);
}

template<typename T>
void	print(T &val)
{
	std::cout << val << std::endl;
}

template<typename T>
void	increment(T &val)
{
	val++;
}

#endif