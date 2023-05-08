/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:52:35 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 16:37:15 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
# define YELLOW "\x1b[33m"
# define RESET  "\x1b[0m"

int main(void)
{
    std::cout << std::endl << YELLOW << "Tests with Animal, Cat and Dog" << RESET << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    std::cout << std::endl << YELLOW << "Tests with WrongAnimal and WrongCat" << RESET << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //won't output the cat sound
        meta->makeSound();

        delete meta;
        delete i;
    }
	return (0);
}

