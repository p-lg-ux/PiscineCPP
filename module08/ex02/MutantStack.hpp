/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:17:25 by pgros             #+#    #+#             */
/*   Updated: 2023/06/28 14:50:40 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <deque>
# include <string>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container>
{
	public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	iterator begin()
	{	return (this->c.begin());}
	
	const_iterator begin() const
	{	return (this->c.begin());}
	
	iterator end()
	{	return (this->c.end());}
	
	const_iterator end() const
	{	return (this->c.end());}
	
	reverse_iterator rbegin()
	{	return (this->c.rbegin());}

	const_reverse_iterator rbegin() const
	{	return (this->c.rbegin());}
	
	reverse_iterator rend()
	{	return (this->c.rend());}

	const_reverse_iterator rend() const
	{	return (this->c.rend());}

};
#endif