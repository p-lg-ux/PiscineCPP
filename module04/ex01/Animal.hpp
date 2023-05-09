/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:14:25 by pgros             #+#    #+#             */
/*   Updated: 2023/05/09 12:29:17 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
	std::string	_type;

	public:
	//constructors and destructors
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();
	//overloads
	Animal& operator=(const Animal& rhs);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};
#endif