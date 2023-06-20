/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:38:01 by pgros             #+#    #+#             */
/*   Updated: 2023/06/20 18:34:16 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		dataVal;
	Data		*ptr;
	uintptr_t	raw;

	dataVal.charAtt = 'a';
	dataVal.strAtt = "HelloWorld";
	dataVal.intAtt = 42;
	std::cout << "dataVal address =\t\t" << &dataVal << std::endl;
	std::cout << "dataVal attributes =\t\t" << dataVal.strAtt << " " << dataVal.charAtt << " " << dataVal.intAtt << std::endl;

	raw = Serializer::serialize(&dataVal);
	std::cout << std::endl << "serialized uintptr_t raw =\t" << raw << std::endl;
	std::cout << "serialized uintptr_t raw =\t" << std::showbase << std::hex << raw << std::dec << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << std::endl << "deserialized Data pointer =\t" << ptr << std::endl;
	std::cout << "original dataVal address =\t" << &dataVal << std::endl;
	std::cout << "Data pointer attributes =\t" << ptr->strAtt << " " << ptr->charAtt << " " << ptr->intAtt << std::endl;

	return (0);
}