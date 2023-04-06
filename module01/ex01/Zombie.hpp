/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:55:53 by pgros             #+#    #+#             */
/*   Updated: 2023/04/03 15:51:42 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
	private:
	std::string	_name;

	public:
	//constructors and destructors
	Zombie();
	Zombie(std::string name);
	~Zombie();
	
	//setter
	void	setName(std::string name);

	void	announce(void);
};
#endif