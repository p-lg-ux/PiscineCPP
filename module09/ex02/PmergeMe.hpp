/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:20 by pgros             #+#    #+#             */
/*   Updated: 2023/07/04 09:40:55 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>

class PmergeMe
{
	public:
	//constructors and destructors
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	//overloads
	PmergeMe& operator=(const PmergeMe& rhs);
};
#endif