/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:38:01 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 16:19:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		data;
	Data		*ptr;
	uintptr_t	raw;

	data.charAtt = 'a';
	data.strAtt = "HelloWorld";
	std::cout << "data address: " << &data << std::endl;
	std::cout << "data attributes: " << data.strAtt << " " << data.charAtt << " " << data.intAtt << std::endl;

	raw = Serializer::serialize(&data);
	std::cout << std::endl << "serialized uintptr_t raw = " << raw << std::endl;
	std::cout << "serialized uintptr_t raw hexa = " << std::hex << raw << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << std::endl << "deserialized Data pointer = " << ptr << std::endl;
	std::cout << "data pointer = " << &data << std::endl;

	return (0);
}