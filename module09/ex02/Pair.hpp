/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:07:14 by pgros             #+#    #+#             */
/*   Updated: 2023/08/03 13:03:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP
# include <iostream>
# include <string>

template<typename T>
class Pair
{
	private:
	T*				_a;
	T*				_b;

	public:
	//constructors and destructors
	Pair<T>() : _a(NULL), _b(NULL){};
	Pair<T>(T& a, T& b) : _a(&a), _b(&b){};
	Pair<T>(const Pair<T>& other) {*this = other;};
	~Pair<T>(){};
	
	//getters
	T*	a() const {return _a;};
	T*	b() const {return _b;};

	//setters
	void seta(T& a) {_a = &a;};
	void setb(T& b) {_b = &b;};

	//overloads
	Pair<T>& operator=(const Pair<T>& rhs)
	{
		_a = rhs.a(); _b = rhs.b(); return (*this);
	};
	bool	operator>(const Pair<T>& rhs) const {return (*_a > *rhs.a());};
	bool	operator<(const Pair<T>& rhs) const {return (*_a < *rhs.a());};
	bool	operator>=(const Pair<T>& rhs) const {return (*_a >= *rhs.a());};
	bool	operator<=(const Pair<T>& rhs) const {return (*_a <= *rhs.a());};
	bool	operator==(const Pair<T>& rhs) const {return (*_a == *rhs.a());};
	bool	operator!=(const Pair<T>& rhs) const {return (*_a != *rhs.a());};
	
	//other
	void sort()
	{
		if (*_a < *_b)
			std::swap(_a, _b);
	};
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const Pair<T>& rhs)
{
	os << "( ";
	if (rhs.a())
		os << *rhs.a();
	else
		os << "NULL";
	os << " , ";
	if (rhs.b())
		os << *rhs.b();
	else
		os << "NULL";
	os << " )";
	return (os);
}

#endif