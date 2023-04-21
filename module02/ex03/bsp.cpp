/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:45:01 by pgros             #+#    #+#             */
/*   Updated: 2023/04/17 15:51:32 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return (false);
	return (point.compare_side(a, b, c) \
			&& point.compare_side(b, c, a) \
			&& point.compare_side(c, a, b));
}