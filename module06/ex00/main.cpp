/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:40:57 by pgros             #+#    #+#             */
/*   Updated: 2023/06/08 17:03:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	std::string str;
	if (argc != 2)
	{
		std::cerr << "One argument required." << std::endl;
		return (1);
	}
	// str = argv[1];
	ScalarConverter::convert(argv[1]);
	return (0);
}