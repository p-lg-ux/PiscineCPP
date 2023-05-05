/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:52:08 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 15:22:14 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
	std::string	_type;

	public:
	//constructors and destructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	~WrongAnimal();
	//overloads
	WrongAnimal& operator=(const WrongAnimal& rhs);

	void makeSound(void) const;
	std::string	getType(void) const;
};
#endif