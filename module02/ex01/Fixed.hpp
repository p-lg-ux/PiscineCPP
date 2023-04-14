/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:46 by pgros             #+#    #+#             */
/*   Updated: 2023/04/11 19:38:15 by pgros            ###   ########.fr       */
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
	Fixed	&operator=(const Fixed& other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		getDecimalNbOfBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &val);

#endif