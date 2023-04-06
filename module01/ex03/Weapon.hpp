/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:19:49 by pgros             #+#    #+#             */
/*   Updated: 2023/04/04 17:37:14 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
	private:
	std::string	_type;

	public:
	//constructors and destructors
	Weapon(std::string type);
	~Weapon();
	const std::string&	getType(void);
	void	setType(std::string type);
};
#endif