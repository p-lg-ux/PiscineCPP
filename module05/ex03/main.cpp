/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:13:34 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 18:25:41 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
# define	BOLD "\033[1;39m"

int main(void)
{
	Bureaucrat	michael("Michael Scott", 1);
	AForm						*ptr;
	Intern me;
	
	/*Tests on ShrubberyCreation*/
	{
		std::cout << std::endl << BOLD << "TESTS ON Intern" << RESET << std::endl;
		ptr = me.makeForm("robotomy request", "Intern");
		if (ptr)
		{
			michael.signForm(*ptr);
			michael.executeForm(*ptr);
		}
		ptr = me.makeForm("presidential pardon", "Meredith");
		if (ptr)
		{
			michael.signForm(*ptr);
			michael.executeForm(*ptr);
		}
		ptr = me.makeForm("unvalid form", "Meredith");
		if (ptr)
		{
			michael.signForm(*ptr);
			michael.executeForm(*ptr);
		}
	}
	std::cout << std::endl << BOLD << "END OF SCOPE" << RESET << std::endl;
	return (0);

}