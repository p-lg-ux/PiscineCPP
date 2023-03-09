/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:17:25 by pgros             #+#    #+#             */
/*   Updated: 2023/03/09 19:57:52 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

# define RED_B		"\033[1;31m"
# define YELLOW_B	"\033[1;33m"
# define BOLD		"\033[1m"
# define RED		"\033[31m"
# define YELLOW		"\033[33m"
# define RESET		"\033[0m"

class Contact
{
	private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_nb;
	std::string	_secret;
	
	std::string	read_input(std::string prompt);

	public:
	//constructors and destructors
	Contact();
	// Contact(const Contact& other);
	~Contact();

	void	setAttributes(void);
	void	displayFull(void);
	void	displayShort(int index);

};
#endif