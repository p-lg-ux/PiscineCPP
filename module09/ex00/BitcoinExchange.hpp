/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:52:01 by pgros             #+#    #+#             */
/*   Updated: 2023/07/01 20:03:50 by pgros            ###   ########.fr       */
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
	// BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	//overloads
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	//setters
	void setInptFilename(std::string filename);
	//other member functions
	bool loadDatabase();
	
};
#endif