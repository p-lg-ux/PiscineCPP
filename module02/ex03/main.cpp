/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:24 by pgros             #+#    #+#             */
/*   Updated: 2023/04/17 16:09:28 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.hpp"

int main( void ) {
	Point A(4, 0);
	Point B(3, 3);
	Point C(0, 0);
	Point P1(2, 2);
	Point P2(2, 1);
	Point P3(3.5f, 1.5f);
	Point P4(4.0f, 0.0f);
	Point P5(15.6f, 10.3f);
	Point P6(2.94f, 1.86f);
	Point P7(2.0f, 2.0 - 0.01);
	Point tab_points[7] = {P1, P2, P3, P4, P5, P6, P7};

	std::cout << "triangle A = " << A << ", B = " << B << ", C = " << C << std::endl;
	for (int i = 0; i<7; i++)
	{
		if (bsp(A, B, C, tab_points[i]))
			std::cout << GREEN << "P" << i + 1 << " = " << tab_points[i] << " is in the triangle" << std::endl;
		else
			std::cout << RED << "P" << i + 1 << " = " << tab_points[i] << " is NOT in the triangle" << std::endl;
	}
}
