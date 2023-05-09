/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:48:53 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 15:53:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	//constructors and destructors
	WrongCat();
	WrongCat(const WrongCat& other);
	~WrongCat();
	//overloads
	WrongCat& operator=(const WrongCat& rhs);
	void makeSound(void) const;
};
#endif