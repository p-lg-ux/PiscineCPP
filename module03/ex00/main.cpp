/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:02:36 by pgros             #+#    #+#             */
/*   Updated: 2023/04/21 18:26:46 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	bob("Bob");
	ClapTrap	jim("Jim");

	bob.attack(jim.getName());
	jim.takeDamage(bob.getAttackDamage());
}