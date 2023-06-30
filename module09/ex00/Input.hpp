/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:21:02 by pgros             #+#    #+#             */
/*   Updated: 2023/06/30 16:20:05 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
# define INPUT_HPP
# include <iostream>
# include <sstream>
# include <string>
# include "errors.hpp"

typedef	std::string	dateString_t;
typedef	std::string	valueString_t;

class Input
{
	private:
	char			_delimiter;
	std::string		_line;
	dateString_t	_date;
	valueString_t	_value_str;
	float			_value;
	error_t			_errors;

	Input();
	
	public:
	//constructors and destructors
	Input(char delim);
	Input(const Input& other);
	~Input();
	//overloads
	Input& operator=(const Input& rhs);
	
	//getters
	char			getDelimiter() const;
	std::string		getLine() const;
	dateString_t	getDate() const;
	valueString_t	getValueStr() const;
	float			getValue() const;
	error_t			getErrors() const;

	//other member functions
	bool	splitLine();
	void	checkDateError();
	void	checkYear();
	void	checkMonth();
	void	checkDay();
	void	checkValueError();
	Input&	operator=(std::string& line);
};
#endif