/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:24:52 by pgros             #+#    #+#             */
/*   Updated: 2023/04/17 16:05:03 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Point::Point()
{
	// std::cout << "Default constructor of Point called." << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Float constructor of Point called." << std::endl;
}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY())
{
	// std::cout << "Copy constructor of Point called." << std::endl;
}
Point::~Point()
{
	// std::cout << "Destructor of Point called." << std::endl;
}
//overloads
Point& Point::operator=(const Point& rhs)
{
	(void)rhs;
	return *this;
}

bool	Point::operator==(const Point& rhs) const
{
	return (_x == rhs._x && _y == rhs._y);
}

const Fixed	&Point::getX() const
{
	return (_x);
}

const Fixed	&Point::getY() const
{
	return (_y);
}

bool	Point::compare_side(Point const a, Point const b, Point const c) const
{
	Fixed	cross_prod_ab_ap;
	Fixed	cross_prod_ab_ac;
	
	//cross-prod AB^AP
	cross_prod_ab_ap = cross_prod(a, b, a, *this);
	//return false if equals 0, that is if the point is on the edge AB
	if (cross_prod_ab_ap == 0)
		return (false);
	//cross-prod AB^AC
	cross_prod_ab_ac = cross_prod(a, b, a, c);
	//compare signs
	//return true if same sign, that is if the point is on the same side of the AB edge as the 3rd apex C
	if (cross_prod_ab_ap * cross_prod_ab_ac > 0)
		return (true);
	//else returns false
	return (false);
}

std::ostream	&operator<<(std::ostream &os, const Point &val)
{
	os << "[ " << val.getX() << " , " << val.getY() << " ]";
	return (os);
}

Fixed	cross_prod(Point const a, Point const b, Point const c, Point const d)
{
	Fixed	res;
	
	res = ((b.getX() - a.getX()) * (d.getY() - c.getY())) \
		- ((d.getX() - c.getX()) * (b.getY() - a.getY())) ;
	return (res);
}

