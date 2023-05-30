/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:42:28 by pgros             #+#    #+#             */
/*   Updated: 2023/05/15 18:11:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructors and destructors
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(value << this->decimalNbOfBits);
}

Fixed::Fixed(const float value)
{
	// (void)value;
	// std::cout << "Float constructor called" << std::endl;
	setRawBits((int) roundf(value * (1 << decimalNbOfBits)));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

int	Fixed::getDecimalNbOfBits(void) const
{
	return (this->decimalNbOfBits);
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->decimalNbOfBits);
}

float	Fixed::toFloat(void) const
{
	/*
	float	f = 0;
	float	power = 1;
	int		raw = this->getRawBits();
	int		sign = 1;

	if (raw < 0)
	{
		sign = -1;
		raw *= -1;
	}
	for (int i = 0; i<8; i++)
		power /= 2;
	for (int i = 0; i<32; i++)
	{
		f += ((raw >> i) & 1) * power;
		power *= 2;
	}
	return (f * sign);
	*/
	return (((float) this->getRawBits()) / (1 << decimalNbOfBits));
}

//overloads
Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed res(this->toFloat() * rhs.toFloat());
	return (res);
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	if (rhs == 0)
	{
		std::cerr << "Division by zero not allowed." << std::endl;
		return (*this);
	}
	Fixed res(this->toFloat() / rhs.toFloat());
	return (res);
}

Fixed	&Fixed::operator++()	//Prefix increment
{
	++rawBits;
	return *this;
}

Fixed	Fixed::operator++(int)	//Postfix increment
{
	Fixed copy = *this;
	++*this;
	return (copy);
}

Fixed	&Fixed::operator--()	//Prefix decrement
{
	--rawBits;
	return *this;
}

Fixed	Fixed::operator--(int)	//Postfix decrement
{
	Fixed copy = *this;
	--*this;
	return (copy);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}
