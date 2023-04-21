/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:21:45 by pgros             #+#    #+#             */
/*   Updated: 2023/04/17 15:28:48 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{
	private:
	const Fixed	_x;
	const Fixed	_y;
	
	public:
	//constructors and destructors
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	~Point();
	//overloads
	Point& 		operator=(const Point& rhs);
	bool		operator==(const Point& rhs) const;
	const Fixed	&getX() const;
	const Fixed	&getY() const;
	bool		compare_side(Point const a, Point const b, Point const c) const;
};

std::ostream	&operator<<(std::ostream &os, const Point &val);
Fixed			cross_prod(Point const a, Point const b, Point const c, Point const d);

#endif