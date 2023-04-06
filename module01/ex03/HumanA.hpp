/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:28:47 by pgros             #+#    #+#             */
/*   Updated: 2023/04/05 16:37:30 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
	std::string	_name;
	Weapon&		_weapon;

	public:
	//constructors and destructors
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void		setWeapon(Weapon& weapon);
	void 		attack(void) const;

};
#endif