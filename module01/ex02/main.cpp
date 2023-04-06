/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:36 by pgros             #+#    #+#             */
/*   Updated: 2023/04/04 17:00:09 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "Adresse de la string en mémoire: " << &str << std::endl;
	std::cout << "Adresse stockée dans stringPTR: " << stringPTR << std::endl;
	std::cout << "Adresse stockée dans stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Valeur de la string: " << str << std::endl;
	std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
	std::cout << "Valeur pointée par stringREF: " << stringREF << std::endl;
	return (0);
}