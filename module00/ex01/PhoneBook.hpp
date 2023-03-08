/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:10:56 by pgros             #+#    #+#             */
/*   Updated: 2023/03/07 16:56:39 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
	Contact _tab[8];
	
	public:
	//constructors and destructors
	PhoneBook();
	// PhoneBook(const PhoneBook& other);
	~PhoneBook();
	//overloads
	// PhoneBook& operator=(const PhoneBook& rhs);
};
#endif