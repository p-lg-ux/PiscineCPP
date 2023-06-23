/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:50:48 by pgros             #+#    #+#             */
/*   Updated: 2023/06/23 17:15:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
# define BOLD	"\033[1;39m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define RESET	"\033[0m"

class A
{
	public:
	int _a;
	A() {};
	A(int a) : _a(a){};
	A(A const &other){*this = other;};
	~A(){};
	A& operator=(const A& rhs){_a  = rhs._a; return (*this);};
};

std::ostream& operator<<(std::ostream &os, const A& val)
{
	os << "_a = " << val._a ;
	return (os);
}

template<typename T>
void printArray(Array<T> &array)
{
	for (unsigned int i=0;i<array.size();i++)
		std::cout << array[i] << std::endl;
}

int main(void)
{
	std::cout << BOLD << "Tests with float" << RESET << std::endl;
	{
		std::cout << YELLOW << "Instanciation" << RESET << std::endl;
		Array<float> array1(3);
		Array<float> array2;
		
		std::cout << "array1.size() = " << array1.size() << std::endl;
		std::cout << "array1 =" << std::endl;
		printArray<float>(array1);
		std::cout << "array2.size() = " << array2.size() << std::endl;
		std::cout << "array2 =" << std::endl;
		printArray<float>(array2);

		array1[0] = 21.21;

		std::cout << YELLOW << "Modify array2" << RESET << std::endl;
		std::cout << "array1 =" << std::endl;
		printArray<float>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<float>(array2);

		std::cout << YELLOW << "Affectation" << RESET << std::endl;
		array2 = array1;
		std::cout << "array1 =" << std::endl;
		printArray<float>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<float>(array2);

		std::cout << YELLOW << "Modify array2" << RESET << std::endl;
		array2[1] = 42.42;
		std::cout << "array1 =" << std::endl;
		printArray<float>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<float>(array2);

		std::cout << YELLOW << "Copy constructor" << RESET << std::endl;
		Array<float> array3(array2);
		std::cout << "array1 =" << std::endl;
		printArray<float>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<float>(array2);
		std::cout << "array3 =" << std::endl;
		printArray<float>(array3);

		std::cout << YELLOW << "Modify array3" << RESET << std::endl;
		try{ array3[3] = 84.84;}
		catch (std::exception &e) { std::cout << "3: " << e.what() << std::endl;}
		try{ array3[2] = 84.84;}
		catch (std::exception &e) { std::cout << "2: " << e.what() << std::endl;}

		std::cout << "array1 =" << std::endl;
		printArray<float>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<float>(array2);
		std::cout << "array3 =" << std::endl;
		printArray<float>(array3);
	}

	std::cout << std::endl << BOLD << "Test with class A" << RESET << std::endl;
	{
		std::cout << YELLOW << "Instanciation" << RESET << std::endl;
		Array<A> array1(3);
		Array<A> array2;
		
		std::cout << "array1.size() = " << array1.size() << std::endl;
		std::cout << "array1 =" << std::endl;
		printArray<A>(array1);
		std::cout << "array2.size() = " << array2.size() << std::endl;
		std::cout << "array2 =" << std::endl;
		printArray<A>(array2);

		array1[0] = 21;

		std::cout << YELLOW << "Modify array2" << RESET << std::endl;
		std::cout << "array1 =" << std::endl;
		printArray<A>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<A>(array2);

		std::cout << YELLOW << "Affectation" << RESET << std::endl;
		array2 = array1;
		std::cout << "array1 =" << std::endl;
		printArray<A>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<A>(array2);

		std::cout << YELLOW << "Modify array2" << RESET << std::endl;
		array2[1] = 42;
		std::cout << "array1 =" << std::endl;
		printArray<A>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<A>(array2);

		std::cout << YELLOW << "Copy constructor" << RESET << std::endl;
		Array<A> array3(array2);
		std::cout << "array1 =" << std::endl;
		printArray<A>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<A>(array2);
		std::cout << "array3 =" << std::endl;
		printArray<A>(array3);

		std::cout << YELLOW << "Modify array3" << RESET << std::endl;
		try{ array3[3] = 84;}
		catch (std::exception &e) { std::cout << "3: " << e.what() << std::endl;}
		try{ array3[2] = 84;}
		catch (std::exception &e) { std::cout << "2: " << e.what() << std::endl;}

		std::cout << "array1 =" << std::endl;
		printArray<A>(array1);
		std::cout << "array2 =" << std::endl;
		printArray<A>(array2);
		std::cout << "array3 =" << std::endl;
		printArray<A>(array3);
	}
	return (0);
}

/*
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/