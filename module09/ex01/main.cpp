/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:18:31 by pgros             #+#    #+#             */
/*   Updated: 2023/09/18 18:05:22 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN	rpn;

	try {
		if (ac != 2)
			throw RPN::ErrorException();
		rpn.processInput(av[1]);
		if (rpn._stack.size() != 1)
			throw RPN::InvalidInputException();
		std::cout << rpn._stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << e.what() << std::endl;
		return (1);
	}
	return (0);
}