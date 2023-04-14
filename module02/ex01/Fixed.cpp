/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:42:28 by pgros             #+#    #+#             */
/*   Updated: 2023/04/12 19:22:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructors and destructors
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << this->decimalNbOfBits);
}

Fixed::Fixed(const float value)
{
	// (void)value;
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int) roundf(value * 256.0));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//overloads
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
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
}

std::ostream	&operator<<(std::ostream &os, const Fixed &val)
{
	os << val.toFloat();
	return (os);
}
