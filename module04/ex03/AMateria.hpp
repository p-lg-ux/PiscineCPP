/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:32:42 by pgros             #+#    #+#             */
/*   Updated: 2023/05/09 15:37:49 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria();
		AMateria(const AMateria &other);
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &rhs);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif