/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:18:31 by pgros             #+#    #+#             */
/*   Updated: 2023/07/03 18:20:05 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		btc.computeInputFile();
	return (0);
}