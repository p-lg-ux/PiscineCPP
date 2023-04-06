/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:18:13 by pgros             #+#    #+#             */
/*   Updated: 2023/04/06 20:04:04 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "Replace.hpp"

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong arguments" << std::endl;
		return (1);
	}
	
	Replace	replace(argv);
	if (!replace.check_args())
		return (1);
	if (!replace.open_in())
		return (1);
	if (!replace.open_out())
		return (1);
	replace.read_content();
	replace.replace();
	replace.write_content();

	return (0);
}
