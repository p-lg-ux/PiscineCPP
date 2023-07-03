/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:52:39 by pgros             #+#    #+#             */
/*   Updated: 2023/07/03 18:10:41 by pgros            ###   ########.fr       */
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
		return((void)(std::cerr << "Error: " << FILE_ERRMSG << std::endl));
	std::getline(ifs_inpt, tmp);
	computeInputLine(ifs_inpt);
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
			displayInput(inpt);
		else
			displayError(inpt);
	}
}

void BitcoinExchange::displayInput(const Input& inpt)
{
	std::map<std::string, float>::iterator it_map;
	float	exchange_rate;

	it_map = _db.lower_bound(inpt.getDate());
	if (inpt.getDate() == it_map->first)
		exchange_rate = it_map->second;
	else
		exchange_rate = (--it_map)->second;
	std::cout 	<< inpt.getDate() \
				<< " => " << inpt.getValueStr() \
				<< " = " << (exchange_rate * inpt.getValue()) \
				<< std::endl;
}

void BitcoinExchange::displayError(const Input& inpt)
{
	ErrorMsgFunc errorFuncs[6] = {
		&BitcoinExchange::errorNoDelim,
		&BitcoinExchange::errorBadInputDate,
		&BitcoinExchange::errorBadInputValue,
		&BitcoinExchange::errorInvalidDate,
		&BitcoinExchange::errorNegValue,
		&BitcoinExchange::errorLargeValue,
	};
	bool	displayed = false;

	std::cerr << "Error : ";
	for (int i = 0, pow = 1; i<6 && pow<=32; i++)
	{
		if (inpt.getErrors() & pow)
		{
			if (displayed)
				std::cerr << " ; and ";
			else
				displayed = true;
			(this->*errorFuncs[i])(inpt);
		}
		pow = pow << 1;
	}
	std::cerr << std::endl;
}

void BitcoinExchange::errorNoDelim(const Input& inpt)
{
	(void)inpt;
	std::cerr << NODELIM_ERRMSG ;
}

void BitcoinExchange::errorBadInputDate(const Input& inpt)
{
	std::cerr << BAD_INPT_ERRMSG << " => " << inpt.getDate();
}

void BitcoinExchange::errorBadInputValue(const Input& inpt)
{
	std::cerr << BAD_INPT_ERRMSG << " => " << inpt.getValueStr();
}

void BitcoinExchange::errorInvalidDate(const Input& inpt)
{
	(void)inpt;
	std::cerr << INVALID_DATE_ERRMSG ;
}

void BitcoinExchange::errorNegValue(const Input& inpt)
{
	(void)inpt;
	std::cerr << NEGVAL_ERRMSG ;
}

void BitcoinExchange::errorLargeValue(const Input& inpt)
{
	(void)inpt;
	std::cerr << LARGEVAL_ERRMSG ;
}