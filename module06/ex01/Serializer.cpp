/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:50:30 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 15:55:33 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <string>

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer::~Serializer()
{}

Serializer& Serializer::operator=(const Serializer& rhs)
{
	(void)rhs;
	return *this;
}