/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:13:34 by pgros             #+#    #+#             */
/*   Updated: 2023/06/01 20:14:23 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	kelly("Kelly Kapoor", 150);
	Form		form28A("28A", 3, 3);
	Form		form28B("28B", 149, 149);
	std::cout << kelly << std::endl;
	std::cout << form28A <<std::endl;
	std::cout << form28B <<std::endl;
	

	/*Exceptions on constructors*/
	std::cout << std::endl << "TESTS ON CONSTRUCTORS" << std::endl;
	try
	{
		Form		form28C("28C", 0, 151);
		std::cout << form28C <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	try
	{
		Form		form28C("28C", 185, 151);
		std::cout << form28C <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	/*Exceptions on signForm()*/
	std::cout << std::endl << "TESTS ON FUNCTION signForm()" << std::endl;
	try
	{
		kelly.signForm(form28B);
	}
	catch(const std::exception& e)
	{
		std::cerr << "first sign form" << e.what() << std::endl;
	}
	
	kelly.upgrade();
	std::cout << kelly <<std::endl;
	
	try
	{
		kelly.signForm(form28B);
	}
	catch(const std::exception& e)
	{
		std::cerr << "second sign form" << e.what() << std::endl;
	}
	std::cout << form28B << std::endl;

	/*Exceptions on beSigned*/
	std::cout << std::endl << "TESTS ON FUNCTION beSigned()" << std::endl;
	try
	{
		Bureaucrat	pam("Pam Beesly", 4);
		std::cout << pam << std::endl;
		form28A.beSigned(pam);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	
	std::cout << std::endl;
	return (0);

}