/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:02:36 by pgros             #+#    #+#             */
/*   Updated: 2023/04/23 17:05:21 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	bob("Bob");
	ClapTrap	jim("Jim");

	bob.attack(jim.getName());
	jim.takeDamage(bob.getAttackDamage());
	for (int i = 0; i< 10; i++)
		jim.beRepaired(1);
	jim.attack(bob.getName());
	bob.takeDamage(jim.getAttackDamage());
	jim.beRepaired(1);
	return (0);
}