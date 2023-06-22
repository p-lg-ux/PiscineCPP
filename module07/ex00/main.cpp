/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:58:44 by pgros             #+#    #+#             */
/*   Updated: 2023/06/22 18:50:41 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
# define BOLD	"\033[1;39m"
# define RESET	"\033[0m"

int main(void)
{
	std::cout << BOLD << "SCHOOL TESTS" << RESET << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << std::endl << BOLD << "MY TESTS" << RESET << std::endl;
	std::cout << std::endl << BOLD << "Tests with int" << RESET << std::endl;
	{
		int	a = 42;
		int	b = 21;
		std::cout << "before swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		swap<int>(a,b);
		std::cout << "after swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		std::cout << "min = " << min<int>(a,b) << std::endl;
		std::cout << "max = " << max<int>(a,b) << std::endl;
	}

	std::cout << std::endl << BOLD << "Tests with float" << RESET << std::endl;
	{
		float	a = 42.42f;
		float	b = 21.21f;
		std::cout << "before swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		swap<float>(a,b);
		std::cout << "after swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		std::cout << "min = " << min<float>(a,b) << std::endl;
		std::cout << "max = " << max<float>(a,b) << std::endl;
	}

	std::cout << std::endl << BOLD << "Tests with char" << RESET << std::endl;
	{
		char	a = 'a';
		char	b = 'b';
		std::cout << "before swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		swap<char>(a,b);
		std::cout << "after swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		std::cout << "min = " << min<char>(a,b) << std::endl;
		std::cout << "max = " << max<char>(a,b) << std::endl;
	}

	std::cout << std::endl << BOLD << "Tests with bool" << RESET << std::endl;
	{
		bool	a = true;
		bool	b = false;
		std::cout << "before swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		swap<bool>(a,b);
		std::cout << "after swap" << std::endl;
		std::cout << "a = " << a << "\t; b = " << b << std::endl;
		std::cout << "min = " << min<bool>(a,b) << std::endl;
		std::cout << "max = " << max<bool>(a,b) << std::endl;
	}
	return (0);
}