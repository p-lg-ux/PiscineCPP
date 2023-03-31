/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:55:27 by pgros             #+#    #+#             */
/*   Updated: 2023/03/31 19:39:09 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

int main(void)
{
	Zombie	first("First");
	Zombie	*second = newZombie("Second");

	first.announce();
	second->announce();
	randomChump("Third");
	first.announce();
	second->announce();
	
	delete second;
	first.announce();
	
	return (0);
}