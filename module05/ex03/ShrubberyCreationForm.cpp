/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:36:30 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 16:10:39 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# define INVERSE	"\x1b[7m"

//constructors and destructors
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation form", 145, 137)
{
	std::cout << INVERSE << "Default constructor of ShrubberyCreationForm called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation form", 145, 137),
	_target(target)
{
	std::cout << INVERSE << "Parameters constructor of ShrubberyCreationForm called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other.getTarget())
{
(void)other;
	std::cout << INVERSE << "Copy constructor of ShrubberyCreationForm called." << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << INVERSE << "Destructor of ShrubberyCreationForm called." << RESET << std::endl;
}

//overloads
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
(void)rhs;
	return *this;
}

//getters
const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::launchExecution() const
{
	std::ofstream	ofs;
	std::string		tree;
	std::string		filename = getTarget() + "_shrubbery";

	ofs.open(filename.data());
	if (!(ofs.is_open()))
	{
		std::cerr << "Could not open " << filename << "." << std::endl;
		return;
	}
	tree = "\n"                                                                                                                                                                                                          
    "                                                                                                                                                                                                      \n"
    "                                                                                                          ░░░░░░      ░░░░                                                                            \n"
    "                                                                                                      ░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒░░                                                                            \n"
    "                                                                            ░░    ░░░░░░              ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                                                                        \n"
    "                                                                    ░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░      ░░░░▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░░░                                                                      \n"
    "                                                                ░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░░░▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                                                                \n"
    "                                                              ░░░░▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒░░                                                            \n"
    "                                                            ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░                                                      \n"
    "                                                            ░░▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░                                                    \n"
    "                                                    ░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒░░                                                    \n"
    "                                                    ▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒░░░░                                                \n"
    "                                                ░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒░░                                                \n"
    "                                              ▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓████▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░                                                \n"
    "                                          ░░░░▒▒▒▒▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓████████▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒                                                \n"
    "                                        ░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒                                              \n"
    "                                      ░░▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒                                              \n"
    "                                      ░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▒▒░░                                              \n"
    "                                        ▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓██▒▒▓▓▒▒▓▓▒▒▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒                                              \n"
    "                                      ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░                                            \n"
    "                                        ▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓██▓▓▓▓████▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░                                          \n"
    "                                      ▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓██████████▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓██▓▓▓▓████▓▓▒▒▒▒▓▓░░▓▓▓▓██▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▒▒░░                                        \n"
    "                                      ░░░░▒▒▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓████▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░                                        \n"
    "                                  ░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░                                    \n"
    "                                ░░▓▓▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▒▒▓▓▓▓▓▓██▓▓▓▓██▓▓██▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒░░                                    \n"
    "                                ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒░░                                      \n"
    "                                ▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▒▒░░                                  \n"
    "                                ▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒░░░░                            \n"
    "                                ▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▓▓▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                              \n"
    "                      ░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓████████▓▓██▓▓▓▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓▓▓▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒                                \n"
    "                    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓████████████▓▓▓▓██████▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▒▒▓▓▒▒▒▒▒▒░░                        \n"
    "                  ░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓████▓▓████▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒                        \n"
    "                  ░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓░░                        \n"
    "                  ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓░░                        \n"
    "                    ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒░░                      \n"
    "                  ░░▒▒▒▒  ░░▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓████████▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒████▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▓▓██▓▓▒▒░░                      \n"
    "                            ▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓██▓▓░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▓▓████▓▓▓▓▓▓████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒                        \n"
    "                            ▓▓▓▓▓▓▒▒▒▒▒▒░░░░▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒░░▓▓▒▒▒▒▓▓▒▒▓▓▓▓██▓▓▓▓██▓▓░░░░██▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓  ▒▒▒▒░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒                            \n"
    "                            ░░      ▒▒░░  ░░▒▒▓▓▒▒▒▒▒▒░░░░▒▒  ░░▒▒████▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒  ░░▒▒▓▓▓▓░░▒▒██▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓      ░░░░░░░░░░▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒                            \n"
    "                                  ░░▒▒░░    ░░▒▒░░    ░░▓▓▒▒░░▒▒▓▓██▓▓▓▓▒▒░░██▒▒▒▒▓▓▓▓▓▓  ░░▓▓▓▓░░▓▓██▒▒▒▒░░▓▓░░  ░░▓▓▒▒          ░░░░    ▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒                            \n"
    "                                                            ░░▓▓▓▓▓▓▓▓▒▒░░░░░░▒▒    ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    ▒▒▒▒      ░░              ▒▒░░▒▒▒▒▓▓██▓▓▒▒▓▓▒▒▓▓░░▓▓▓▓▓▓▓▓▒▒▒▒░░                            \n"
    "                                                                  ░░░░▒▒                ░░▓▓▓▓▓▓▓▓▓▓░░    ▓▓                        ░░▒▒░░▒▒████░░░░░░▒▒▒▒▓▓░░  ▒▒▒▒▒▒░░                              \n"
    "                                                                    ░░░░                    ▓▓▓▓▓▓▓▓    ▓▓▒▒                        ▒▒▓▓▒▒▓▓▒▒▓▓        ▒▒▒▒░░                                        \n"
    "                                                                                              ▓▓▓▓▓▓░░▓▓▒▒                            ▓▓░░▒▒░░░░          ░░                                          \n"
    "                                                                                              ▓▓▓▓▓▓▒▒░░                                                                                              \n"
    "                                                                                              ▓▓▓▓▓▓▒▒                                                                                                \n"
    "                                                                                              ▓▓▓▓▓▓░░                                                                                                \n"
    "                                                                                              ▓▓▓▓▓▓░░                                                                                                \n"
    "                                                                                              ▓▓▒▒▓▓▒▒                                                                                                \n"
    "                                                                                              ▓▓▓▓▓▓▒▒                                                                                                \n"
    "                                                                                              ▓▓▓▓▓▓▓▓                                                                                                \n"
    "                                                                                              ▒▒▓▓▓▓▓▓                                                                                                \n"
    "                                                                                            ░░▒▒▓▓▓▓▓▓                                                                                                \n"
    "                                                                                        ░░▒▒▒▒▓▓▓▓▓▓▓▓▒▒░░░░                                                                                          \n"
    "                                                                          ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░▒▒░░                                                                            \n";
	ofs << tree;
	ofs.close();
}