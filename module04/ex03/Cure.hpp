/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:40:45 by pgros             #+#    #+#             */
/*   Updated: 2023/05/10 15:10:57 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	Cure();
	Cure(const Cure& other);
	~Cure();
	Cure &operator=(const Cure &rhs);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif