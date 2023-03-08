/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:17:25 by pgros             #+#    #+#             */
/*   Updated: 2023/03/08 19:35:25 by pgros            ###   ########.fr       */
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
	// Contact(const Contact& other);
	~Contact();

	/*	setters	*/
	void	setFirstName(std::string str);
	void	setLastName(std::string str);
	void	setNickname(std::string str);
	void	setPhoneNumber(std::string str);
	void	setSecret(std::string str);

	/*	getters	*/
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickname(void);
	std::string	getPhoneNumber(void);
	std::string	getSecret(void);
	//overloads
	// Contact& operator=(const Contact& rhs);
};
#endif