/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:45:24 by pgros             #+#    #+#             */
/*   Updated: 2023/04/17 15:56:23 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
# define BSP_HPP

# include "Point.hpp"

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define RESET		"\033[0m"

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif