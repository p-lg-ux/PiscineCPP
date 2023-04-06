/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:55:27 by pgros             #+#    #+#             */
/*   Updated: 2023/04/04 16:15:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main(void)
{
	int		n = 5;
	int		i = -1;
	Zombie	*horde = zombieHorde(n, "Chump");

	while (++i < n)
		horde[i].announce();
	std::cout << std::endl;
	horde[0].setName("First");
	horde[n - 1].setName("Last");
	i = -1;
	while (++i < n)
		horde[i].announce();
	
	delete [] horde;
	std::cout << "End of program" << std::endl;
	return (0);
}