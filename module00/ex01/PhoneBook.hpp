/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:10:56 by pgros             #+#    #+#             */
/*   Updated: 2023/03/08 20:32:18 by pgros            ###   ########.fr       */
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
	int		_nb_of_contacts;
	
	public:
	//constructors and destructors
	PhoneBook();
	// PhoneBook(const PhoneBook& other);
	~PhoneBook();

	void	add();
	void	search();
	//overloads
	// PhoneBook& operator=(const PhoneBook& rhs);
};
#endif