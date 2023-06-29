/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:18:31 by pgros             #+#    #+#             */
/*   Updated: 2023/06/29 21:05:44 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "Input.hpp"

int main(int ac, char **av)
{
	std::string 	filename;
	std::string 	line;
	std::ifstream	ifs;
	Input			inpt(',');

	if (ac != 2)
	{
		std::cerr << "Error: " << FILE_ERRMSG << std::endl;
		return (1);
	}
	filename = av[1];
	ifs.open(filename.data());
	if (!ifs.is_open())
	{
		std::cerr << "Error: " << FILE_ERRMSG << std::endl;
		return (1);
	}
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		inpt = line;
		std::cout << "-------------" << std::endl;
		std::cout << "line: " << inpt.getLine() << std::endl;
		if (!inpt.getErrors())
		{
			std::cout << "date: " << inpt.getDate() << std::endl;
			std::cout << "value: " << inpt.getValueStr() << std::endl;			
		}
		else
			std::cout << "Error: " << inpt.getErrors() << std::endl;
	}
	return (0);
}