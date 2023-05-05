/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:02:36 by pgros             #+#    #+#             */
/*   Updated: 2023/04/26 15:17:57 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "Bob:" << std::endl;
	ClapTrap	bob("Bob");
	std::cout << "Jim:" << std::endl;
	ScavTrap	jim("Jim");
	std::cout << "Sam:" << std::endl;
	FragTrap	sam("Sam");
	std::cout << "Tom:" << std::endl;
	DiamondTrap	tom("Tom");
	std::cout << std::endl << "DiamondTrap Tom features:" << std::endl;
	std::cout << "\tname: " << tom.getName() << std::endl;
	std::cout << "\tclap name: " << tom.ClapTrap::getName() << std::endl;
	std::cout << "\thit points: " << tom.getHitPoints() << std::endl; 
	std::cout << "\tenergy points: " << tom.getEnergyPoints() << std::endl; 
	std::cout << "\tattack damage: " << tom.getAttackDamage() << std::endl; 
	bob.attack(jim.getName());
	jim.takeDamage(bob.getAttackDamage());
	tom.attack(sam.getName());
	sam.takeDamage(tom.getAttackDamage());
	// sam.attack(tom.getName());
	
	sam.highFiveGuys();
	jim.getName();
	tom.whoAmI();
	return (0);
}