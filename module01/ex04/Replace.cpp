/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:56:40 by pgros             #+#    #+#             */
/*   Updated: 2023/04/06 20:02:50 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Replace::Replace(char **args)
{
	this->_filename = args[1];
	this->_s1 = args[2];
	this->_s2 = args[3];
	this->_filename_rep = args[1];
	this->_filename_rep += ".replace";
	//std::cout << "Default constructor of Replace called." << std::endl;
}

Replace::~Replace()
{
	this->ifs.close();
	this->ofs.close();
	//std::cout << "Destructor of Replace called." << std::endl;
}

bool	Replace::check_args(void) const
{
	if (!this->_s1.empty())
		return (true);
	std::cerr << "Argument s1 cannot be empty" << std::endl;
	return (false);
}

bool	Replace::open_in(void)
{
	this->ifs.open(this->_filename.data());
	if (this->ifs.is_open())
		return (true);
	std::cerr << "Could not open file \"" << this->_filename << "\"" << std::endl;
	return (false);
}

bool	Replace::open_out(void)
{
	this->ofs.open(this->_filename_rep.data());
	if (this->ofs.is_open())
		return (true);
	std::cerr << "Could not open file \"" << this->_filename_rep << "\"" << std::endl;
	return (false);
}

void	Replace::read_content(void)
{
	std::getline(this->ifs, this->_content, (char) EOF);
}

void	Replace::write_content(void)
{
	this->ofs << this->_content;
}

void	Replace::print_content(void) const
{
	std::cout << "content:" << std::endl << this->_content << std::endl;
}

void	Replace::replace(void)
{
	std::string::size_type	pos;

	while (1)
	{
		pos = this->_content.find(this->_s1);
		if (pos == std::string::npos)
			break;
		this->_content.erase(pos, this->_s1.length());
		this->_content.insert(pos, this->_s2.data());
	}
}
