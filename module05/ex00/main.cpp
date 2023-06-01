/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:13:34 by pgros             #+#    #+#             */
/*   Updated: 2023/06/01 19:58:54 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	kelly("Kelly Kapoor", 150);
	Bureaucrat	pam("Pam Beesly", 1);
	// Bureaucrat	jim(toby);
	std::cout << pam << std::endl << kelly << std::endl /*<< jim << std::endl*/;
	pam.downgrade();
	std::cout << pam << std::endl;
	pam.upgrade();
	std::cout << pam << std::endl;
	try
	{
		pam.upgrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		kelly.downgrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat michael("Michael Scott", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat toby("Toby Flenderson", 546574654);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}