/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:23:13 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 16:55:09 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal
{
	public:
	//constructors and destructors
	Cat();
	Cat(const Cat& other);
	~Cat();
	//overloads
	Cat& operator=(const Cat& rhs);

	void	makeSound(void) const;
};
#endif