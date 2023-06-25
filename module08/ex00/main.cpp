/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:21:12 by pgros             #+#    #+#             */
/*   Updated: 2023/06/25 23:24:41 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"
# define BOLD	"\033[1;39m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define RESET	"\033[0m"

template<typename T>
void	test(T &c, int n)
{
	try{
		easyfind(c, n); 
		std::cout << n << " found." << std::endl;
	}
	catch (std::exception &e){
		std::cout << n << " not found." << std::endl;
	}
}

template<typename T>
void	print(T &c)
{
	std::cout << "{ ";
	for (typename T::iterator it = c.begin(); it!=c.end(); ++it)
    	std::cout << *it << ", ";
	std::cout << "};" << std::endl;
}

int main(void)
{
	std::vector<int> v;
	std::list<int> l;
	v.assign(4, 1);
	v.insert(v.end(), 3);
	l.assign(4, 1);
	l.insert(l.end(), 3);

	std::cout << BOLD << "Tests with vector" << RESET << std::endl;
	std::cout << "vector v = " ;
	print(v);
	test(v, 1);
	test(v, 2);
	test(v, 3);

	std::cout << BOLD << "Tests with list" << RESET << std::endl;
	std::cout << "list l = " ;
	print(l);
	test(l, 1);
	test(l, 2);
	test(l, 3);
	
	return (0);
}