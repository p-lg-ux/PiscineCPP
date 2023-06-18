/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:08:11 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 17:51:25 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include <cstdlib>
#include <ctime>

Base*	instantiateA(void)
{
	std::cout << "Instantiate A" << std::endl;
	return (new A);
}

Base*	instantiateB(void)
{
	std::cout << "Instantiate B" << std::endl;
	return (new B);
}

Base*	instantiateC(void)
{
	std::cout << "Instantiate C" << std::endl;
	return (new C);
}

Base*	generate(void)
{
	instantiateFunc f[] = {
		&instantiateA,
		&instantiateB,
		&instantiateC,
	};
	
	std::srand(std::time(0));
	return(f[std::rand() % 3]());
}

void	identify(Base *p)
{
	A	*ptrA;
	B	*ptrB;
	C	*ptrC;
	
	ptrA = dynamic_cast<A*>(p);
	if (ptrA != NULL)
		return ((void) (std::cout << "Pointer identified as A" << std::endl));
	ptrB = dynamic_cast<B*>(p);
	if (ptrB != NULL)
		return ((void) (std::cout << "Pointer identified as B" << std::endl));
	ptrC = dynamic_cast<C*>(p);
	if (ptrC != NULL)
		return ((void) (std::cout << "Pointer identified as C" << std::endl));
	return ((void) (std::cout << "No type found" << std::endl));
}

void	identify(Base &p)
{
	try {A &refA = dynamic_cast<A&>(p); (void)refA;}
	catch (const std::exception &e_A)
	{
		try {B &refB = dynamic_cast<B&>(p); (void)refB;}
		catch (const std::exception &e_B)
		{
			try {C &refC = dynamic_cast<C&>(p);(void)refC;}
			catch (const std::exception &e_C)
			{
				std::cout << "No type found" << std::endl;
				return;
			}
			std::cout << "Reference identified as C" << std::endl;
			return;
		}
		std::cout << "Reference identified as B" << std::endl;
		return;
	}
	std::cout << "Reference identified as A" << std::endl;
}