/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:55:22 by pgros             #+#    #+#             */
/*   Updated: 2023/05/12 17:42:56 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
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
*/

MateriaSource::MateriaSource()
{
	std::cout << GREEN << "Default constructor of MateriaSource called." << RESET << std::endl;
	for (int i=0;i<4;i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << GREEN << "Copy constructor of MateriaSource called." << RESET << std::endl;
	for (int i=0; i<4; i++)
	{
		if (other.getMateria(i) == NULL)
			_materias[i] = NULL;
		else
			_materias[i] = other.getMateria(i)->clone();
	}
}

MateriaSource::~MateriaSource()
{
	for (int i=0;i<4;i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
	}
	std::cout << GREEN << "Destructor of MateriaSource called." << RESET << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i=0; i<4; i++)
	{
		delete _materias[i];
		if (rhs.getMateria(i) == NULL)
			_materias[i] = NULL;
		else
			_materias[i] = rhs.getMateria(i)->clone();
	}
	return (*this);
}

AMateria* MateriaSource::getMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (_materias[idx]);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i=0;i<4;i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i=0;i<4;i++)
	{
		if (_materias[i] != NULL && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (NULL);
}
