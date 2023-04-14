/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:24 by pgros             #+#    #+#             */
/*   Updated: 2023/04/14 19:05:23 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) - Fixed( 100 ) );
	Fixed const c( Fixed( 424.2f ) * Fixed( 0.1f ) );
	Fixed const d( Fixed( 424.2f * 0.1f) );
	Fixed const e( Fixed( 424.2f ) / Fixed( 10 ) );
	
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "max = " << Fixed::max(a , Fixed::max(b, Fixed::max(c , d))) << std::endl;
	std::cout << "min = " << Fixed::min(a , Fixed::min(b, Fixed::min(c , d))) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	if (d == e)
		std::cout << "d equals e" <<std::endl;
	else
		std::cout << "d does not equal e" <<std::endl;
	if (d == c)
		std::cout << "d equals c" <<std::endl;
	else
		std::cout << "d does not equal c" <<std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	return (0);
}
