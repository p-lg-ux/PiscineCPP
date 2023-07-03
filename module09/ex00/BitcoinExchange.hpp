/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:52:01 by pgros             #+#    #+#             */
/*   Updated: 2023/07/03 18:06:18 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include "Input.hpp"

class BitcoinExchange
{
	typedef	void	(BitcoinExchange::*ErrorMsgFunc)(const Input&);

	private:
	static std::string const		_dbFilename;
	std::string						_inptFilename;
	void	errorNoDelim(const Input& inpt);
	void	errorBadInputDate(const Input& inpt);
	void	errorBadInputValue(const Input& inpt);
	void	errorInvalidDate(const Input& inpt);
	void	errorNegValue(const Input& inpt);
	void	errorLargeValue(const Input& inpt);

	public:
	std::map<std::string, float>	_db;
	//constructors and destructors
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	//overloads
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	//setters
	void setInptFilename(std::string filename);
	//other member functions
	bool	loadDatabase();
	void	computeInputFile();
	void	computeInputLine(std::ifstream& ifs_inpt);
	void	displayInput(const Input& inpt);
	void	displayError(const Input& inpt);
};
#endif