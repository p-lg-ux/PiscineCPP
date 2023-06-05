/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:52:34 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 18:26:44 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
class Intern
{
    private:
    AForm *_newShrubberyCreationForm(void);
    AForm *_newRobotomyRequestForm(void);
    AForm *_newPresidentialPardonForm(void);

    public:
    //constructors and destructors
    //overload
    Intern &operator=(const Intern &rhs);

    //member function
    AForm *makeForm(std::string formName, std::string target);
};*/

Intern::Intern()
{
	std::cout << INVERSE << "Default constructor of Intern called." << RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << INVERSE << "Copy constructor of Intern called." << RESET << std::endl;
}

Intern::~Intern()
{
	std::cout << INVERSE << "Destructor of Intern called." << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm 			*ptr;
	std::string		names[] = {
		"presidential pardon", "robotomy request", "shrubbery creation"
	};
	AllocationFunction	f[] = {
		&Intern::_newPresidentialPardonForm,
		&Intern::_newRobotomyRequestForm,
		&Intern::_newShrubberyCreationForm,
	};

	for (int i=0;i<3;i++)
	{
		if (formName == names[i])
		{
			ptr = (this->*f[i])(target);
			std::cout << GREEN << "Intern creates " << ptr->getName() << RESET << std::endl;
			return (ptr);
		}
	}
	std::cerr << RED << "Form name \"" << formName << "\" does not exist." << RESET << std::endl;
	return (NULL);
}

AForm *Intern::_newShrubberyCreationForm(std::string target)
{
	return(new ShrubberyCreationForm(target));
}

AForm *Intern::_newRobotomyRequestForm(std::string target)
{
	return(new RobotomyRequestForm(target));
}

AForm *Intern::_newPresidentialPardonForm(std::string target)
{
	return(new PresidentialPardonForm(target));
}
