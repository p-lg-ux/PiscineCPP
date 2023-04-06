/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:39:39 by pgros             #+#    #+#             */
/*   Updated: 2023/04/06 20:02:20 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

class Replace
{
	private:
	std::string		_filename;
	std::string		_filename_rep;
	std::string		_s1;
	std::string		_s2;
	std::string		_content;

	std::ifstream	ifs;
	std::ofstream	ofs;
	
	public:
	Replace(char **args);
	~Replace();
	bool	check_args(void) const;
	bool	open_in(void);
	bool	open_out(void);
	void	read_content(void);
	void	write_content(void);	
	void	print_content(void) const;
	void	replace(void);
};

#endif