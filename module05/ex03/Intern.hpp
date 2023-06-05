/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:29:01 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 18:19:40 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"
# define GREEN	    "\x1b[32m"
# define RED	    "\x1b[31m"
# define INVERSE	"\x1b[7m"
# define RESET		"\x1b[0m"

class Intern
{
    typedef     AForm * (Intern::*AllocationFunction)(std::string target);

    private:
    AForm *_newShrubberyCreationForm(std::string target);
    AForm *_newRobotomyRequestForm(std::string target);
    AForm *_newPresidentialPardonForm(std::string target);

    public:
    //constructors and destructors
    Intern();
    Intern(const Intern &other);
    ~Intern();
    //overload
    Intern &operator=(const Intern &rhs);

    //member function
    AForm *makeForm(std::string formName, std::string target);
};

#endif