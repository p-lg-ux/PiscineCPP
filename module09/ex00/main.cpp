/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:18:31 by pgros             #+#    #+#             */
/*   Updated: 2023/07/01 20:01:17 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "Input.hpp"
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange	btc;

	if (ac != 2)
	{
		std::cerr << "Error: " << FILE_ERRMSG << std::endl;
		return (1);
	}
	btc.setInptFilename(av[1]);
	if (btc.loadDatabase())
	{
		std::cout << "map size = " << btc._db.size() << std::endl;
		std::map<std::string, float>::iterator it = btc._db.begin();
		for (int i = 0; i < 5; i++,it++)
			std::cout << "date: " << it->first << " ; val: " << it->second << std::endl;
	}
	return (0);
}