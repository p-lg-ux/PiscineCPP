/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:46 by pgros             #+#    #+#             */
/*   Updated: 2023/04/11 16:40:24 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
	int					rawBits;
	int const static	decimalNbOfBits = 8;

	public:
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed(void);
	Fixed	&operator=(const Fixed&);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		getDecimalNbOfBits(void) const;
};

#endif