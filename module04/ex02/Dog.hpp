/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:19:33 by pgros             #+#    #+#             */
/*   Updated: 2023/05/08 18:08:40 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{
	private:
	Brain *_brain;

	public:
	//constructors and destructors
	Dog();
	Dog(const Dog& other);
	~Dog();
	//overloads
	Dog& operator=(const Dog& rhs);

	void makeSound(void) const;
	Brain		*getBrainAddress(void) const;

};
#endif