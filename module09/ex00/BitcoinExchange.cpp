/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:52:39 by pgros             #+#    #+#             */
/*   Updated: 2023/07/02 22:46:06 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Input.hpp"
#include "errors.hpp"
#include <iostream>
#include <string>

std::string const BitcoinExchange::_dbFilename = "data.csv";

//constructors and destructors
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange::~BitcoinExchange()
{
}

//overloads
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
(void)rhs;
	return *this;
}

void BitcoinExchange::setInptFilename(std::string filename)
{
	_inptFilename = filename;
}


bool BitcoinExchange::loadDatabase()
{
	std::ifstream	ifs_db(_dbFilename.data());
	Input			inpt(',', 0);
	std::string		line;

	if (!ifs_db.is_open())
		return(std::cerr << "Error: " << DB_ERRMSG << std::endl, false);
	std::getline(ifs_db, line);
	while (!ifs_db.eof())
	{
		std::getline(ifs_db, line);
		if (line.empty())
			continue;
		inpt = line;
		if (inpt.isValid())
			_db[inpt.getDate()] = inpt.getValue();
		else
			return(std::cerr << "Error: " << DB_ERRMSG << std::endl, false);
	}
	return (true);
}

void BitcoinExchange::computeInputFile()
{
	std::ifstream	ifs_inpt(_inptFilename.data());
	std::string		tmp;

	if (!ifs_inpt.is_open())
		return((void) std::cerr << "Error: " << FILE_ERRMSG << std::endl);
	std::getline(ifs_inpt, tmp);
	computeInputLine();
}

void BitcoinExchange::computeInputLine(std::ifstream& ifs_inpt)
{
	Input			inpt('|', 1000);
	std::string line;

	while (!ifs_inpt.eof())
	{
		std::getline(ifs_inpt, line);
		if (line.empty())
			continue;
		inpt = line;
		if (inpt.isValid())
			_db[inpt.getDate()] = inpt.getValue();
		else
			displayError();
	}
}
