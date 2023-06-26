/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:31:23 by pgros             #+#    #+#             */
/*   Updated: 2023/06/26 16:25:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <list>

class Span
{
	private:
	std::list<int>	_L;
	unsigned int	_N;

	public:
	//constructors and destructors
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	//overloads
	Span& operator=(const Span& rhs);
	//getters
	std::list<int> const	&get_L() const;
	unsigned int			get_N() const;
	//functions
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	
	//exceptions
	class SpanFullException : public std::exception{
		virtual const char *what() const throw();
	};

	class TooFewElementsException : public std::exception{
		virtual const char *what() const throw();
	};

	template<typename T>
	void addNumber(typename T::iterator first, typename T::iterator last)
	{
		if (_L.size() + std::distance(first, last) <= _N)
		{
			for (;first!=last;first++)
				_L.push_back(*first);
		}
		else
			throw SpanFullException();
	}
};

std::ostream&	operator<<(std::ostream &os, Span const & s);

#endif