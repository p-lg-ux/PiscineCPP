/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearch.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:04:45 by pgros             #+#    #+#             */
/*   Updated: 2023/08/03 13:13:49 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCH_HPP
# define BINARYSEARCH_HPP
# include <vector>
# include <deque>

/*
Binary Search function takes a range of iterators (first, last) on a sorted set
of elements (either a vector or deque container) and a value, and returns an
iterator on the element before which the value must be inserted.
*/



/*-------------------- Vector --------------------*/

template <typename T>
static typename std::vector<T>::iterator binary_search(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T &val)
{
	typename std::vector<T>::iterator middle;

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


/*-------------------- Deque --------------------*/

template <typename T>
static typename std::deque<T>::iterator binary_search(typename std::deque<T>::iterator first, typename std::deque<T>::iterator last, T &val)
{
	typename std::deque<T>::iterator middle;

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

#endif