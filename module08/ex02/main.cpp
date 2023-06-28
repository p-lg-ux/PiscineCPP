/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:32:55 by pgros             #+#    #+#             */
/*   Updated: 2023/06/28 15:04:51 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
# define BOLD	"\033[1;39m"
# define RESET	"\033[0m"

int main()
{
	std::cout << BOLD << "Tests with MutantStack" << RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);	
	}

	std::cout << std::endl << BOLD << "Tests with List" << RESET << std::endl;
	{
		std::list<int> myList;
		myList.push_back(5);
		myList.push_back(17);
		std::cout << myList.back() << std::endl;
		myList.pop_back();
		std::cout << myList.size() << std::endl;
		myList.push_back(3);
		myList.push_back(5);
		myList.push_back(737);
		//[...]
		myList.push_back(0);
		std::list<int>::iterator it = myList.begin();
		std::list<int>::iterator ite = myList.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}