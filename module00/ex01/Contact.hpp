/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:17:25 by pgros             #+#    #+#             */
/*   Updated: 2023/03/07 16:49:19 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class Contact
{
	private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_nb;
	std::string	_secret;

	public:
	//constructors and destructors
	Contact();
	Contact(const Contact& other);
	~Contact();
	//overloads
	Contact& operator=(const Contact& rhs);
};
#endif