/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:48:30 by pgros             #+#    #+#             */
/*   Updated: 2023/05/12 16:16:09 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();
		MateriaSource & operator=(const MateriaSource &rhs);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		AMateria* getMateria(int idx) const;
};

#endif