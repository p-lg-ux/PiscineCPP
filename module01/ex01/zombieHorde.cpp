/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:40:34 by pgros             #+#    #+#             */
/*   Updated: 2023/04/03 15:54:12 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	int 	i = 0;

	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}