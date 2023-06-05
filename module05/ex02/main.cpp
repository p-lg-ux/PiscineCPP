/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:13:34 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 16:00:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
# define	BOLD "\033[1;39m"

int main(void)
{
	Bureaucrat	kelly("Kelly Kapoor", 45);
	Bureaucrat	pam("Pam Beesly", 25);
	Bureaucrat	michael("Michael Scott", 1);
	Bureaucrat	toby("Toby Flenderson", 150);
	PresidentialPardonForm		form28A("Creed");
	RobotomyRequestForm			form28B("Angela");
	ShrubberyCreationForm		form28C("garden");
	std::cout << toby << std::endl;
	std::cout << kelly << std::endl;
	std::cout << pam << std::endl;
	std::cout << michael << std::endl;
	
	/*Tests on ShrubberyCreation*/
	{
		std::cout << std::endl << BOLD << "TESTS ON ShrubberyCreation Form" << RESET << std::endl;
		
		std::cout << form28C << std::endl;
		michael.executeForm(form28C);
		michael.signForm(form28C);
		std::cout << form28C << std::endl;
		toby.executeForm(form28C);
		kelly.executeForm(form28C);
		pam.executeForm(form28C);
		michael.executeForm(form28C);
	}

	/*Tests on RobotomyRequest*/
	{
		std::cout << std::endl << BOLD << "TESTS ON RobotomyRequest Form" << RESET << std::endl;
		
		std::cout << form28B << std::endl;
		michael.executeForm(form28B);
		michael.signForm(form28B);
		std::cout << form28B << std::endl;
		toby.executeForm(form28B);
		kelly.executeForm(form28B);
		pam.executeForm(form28B);
		michael.executeForm(form28B);
	}

	/*Tests on PresidentialPardon*/
	{
		std::cout << std::endl << BOLD << "TESTS ON PresidentialPardon Form" << RESET << std::endl;
		
		std::cout << form28A << std::endl;
		michael.executeForm(form28A);
		michael.signForm(form28A);
		std::cout << form28A << std::endl;
		toby.executeForm(form28A);
		kelly.executeForm(form28A);
		pam.executeForm(form28A);
		michael.executeForm(form28A);
	}

/*
	// Exceptions on beSigned
	std::cout << std::endl << BOLD << "TESTS ON FUNCTION beSigned()" << RESET << std::endl;
	try
	{
		std::cout << pam << std::endl;
		form28A.beSigned(pam);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

*/
	std::cout << std::endl << BOLD << "END OF SCOPE" << RESET << std::endl;
	return (0);

}