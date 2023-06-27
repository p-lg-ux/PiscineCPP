/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:57:07 by pgros             #+#    #+#             */
/*   Updated: 2023/06/27 17:42:47 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

//constructors and destructors
Span::Span()
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span()
{}

std::list<int> const	&Span::get_L() const
{
	return (_L);
}

unsigned int	Span::get_N() const
{
	return (_N);
}

//overloads
Span& Span::operator=(const Span& rhs)
{
	_L = rhs.get_L();
	_N = rhs.get_N();
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_L.size() < _N)
		_L.push_back(number);
	else
		throw SpanFullException();
}

void Span::addMultipleNumber(std::list<int>::const_iterator first, std::list<int>::const_iterator last)
{
	if (_L.size() == _N)
		throw SpanFullException();
	else if (_L.size() + std::distance(first, last) <= _N)
		_L.insert(_L.end(), first, last);
	else
		throw NotEnoughSpaceException();
}


int		Span::shortestSpan() const
{
	std::list<int>	cpy = _L;

	if (_L.size() == 0 || _L.size() == 1)
		throw TooFewElementsException();
	cpy.sort();
	std::transform(++cpy.begin(), cpy.end(), cpy.begin(), cpy.begin(), std::minus<int>());
	return(*std::min_element(cpy.begin(), --cpy.end()));
	
}

int		Span::longestSpan() const
{
	if (_L.size() == 0 || _L.size() == 1)
		throw TooFewElementsException();
	return (*std::max_element(_L.begin(), _L.end()) - *std::min_element(_L.begin(), _L.end()));
}

const char *Span::SpanFullException::what() const throw()
{
	return ("Can not add number: Span object is full.");
}

const char *Span::NotEnoughSpaceException::what() const throw()
{
	return ("Can not add number: Span object does not have enough space left.");
}

const char *Span::TooFewElementsException::what() const throw()
{
	return ("Can not find span: Span object only has 0 or 1 element.");
}

std::ostream&	operator<<(std::ostream &os, Span const & s)
{
	std::list<int>::const_iterator	it = s.get_L().begin();
	os << "{ ";
	for(;it != s.get_L().end(); it++)
		os << *it << ", ";
	os << "}";
	return (os);
}
