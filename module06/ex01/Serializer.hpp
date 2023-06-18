/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:38:57 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 16:10:38 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>
# include <stdint.h> //uintptr_t
# include "Data.hpp"

class Serializer
{
	public:
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);

	private:
	//constructors and destructors
	Serializer();
	Serializer(const Serializer& other);
	~Serializer();
	//overloads
	Serializer& operator=(const Serializer& rhs);
};
#endif