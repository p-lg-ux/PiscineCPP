/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:52:01 by pgros             #+#    #+#             */
/*   Updated: 2023/07/02 22:43:28 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <string>
# include <fstream>

class BitcoinExchange
{
	private:
	static std::string const		_dbFilename;
	std::string						_inptFilename;

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
};
#endif