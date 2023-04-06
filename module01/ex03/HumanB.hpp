/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:34:15 by pgros             #+#    #+#             */
/*   Updated: 2023/04/05 16:37:44 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
	std::string	_name;
	Weapon*		_weapon;

	public:
	//constructors and destructors
	HumanB(std::string name);
	~HumanB();
	void		setWeapon(Weapon& weapon);
	void		attack(void) const;
};
#endif