/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:46 by pgros             #+#    #+#             */
/*   Updated: 2023/04/14 13:09:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
	int					rawBits;
	int const static	decimalNbOfBits = 8;

	public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed(const float value);
	Fixed(const int value);
	~Fixed(void);
	//asssignment operator overload
	Fixed	&operator=(const Fixed& other);
	//comparison operators overloads
	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;
	//arithmetic operators overloads
	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator*(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;
	//incrementation and decrementation operators overloads
	Fixed	&operator++();		//Prefix increment
	Fixed	operator++(int);	//Postfix increment
	Fixed	&operator--();		//Prefix decrement
	Fixed	operator--(int);	//Postfix decrement
	//Min & max functions
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		getDecimalNbOfBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &val);

#endif