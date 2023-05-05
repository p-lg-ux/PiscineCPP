/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:02:36 by pgros             #+#    #+#             */
/*   Updated: 2023/04/25 13:14:06 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	bob("Bob");
	ClapTrap	jim("Jim");
	FragTrap	sam("Sam");

	bob.attack(jim.getName());
	jim.takeDamage(bob.getAttackDamage());
	jim.attack(bob.getName());
	bob.takeDamage(jim.getAttackDamage());
	jim.beRepaired(10);
	
	sam.attack(jim.getName());
	jim.takeDamage(sam.getAttackDamage());
	jim.beRepaired(10);
	jim.attack(sam.getName());
	sam.highFiveGuys();
	jim = sam;
	jim.attack(bob.getName());
	bob.takeDamage(jim.getAttackDamage());
	return (0);
}