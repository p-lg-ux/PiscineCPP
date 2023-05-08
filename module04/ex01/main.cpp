/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:52:35 by pgros             #+#    #+#             */
/*   Updated: 2023/05/08 19:35:05 by pgros            ###   ########.fr       */
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
    {
        std::cout << YELLOW << "Runtime polymorphism tests" << RESET << std::endl;
        const Animal *j = new Dog();    
        const Animal *i = new Cat();
    
        j->makeSound();
        i->makeSound();
        
        delete i;
        delete j;
    }
    {
        std::cout << std::endl << YELLOW << "Runtime polymorphism with array" << RESET << std::endl;
        Animal  *tab[4];
        Dog     doggo;
        Cat     catsy;
        (doggo.getBrainAddress())->setIdea("I'm the goodest of the bois!");
        (catsy.getBrainAddress())->setIdea("Leave me alone, I'm the superior being here.");
        (catsy.getBrainAddress())->setIdea("LASER! *zooooooom*");
        tab[0] = new Dog(doggo);
        tab[1] = new Dog(doggo);
        tab[2] = new Cat(catsy);
        tab[3] = new Cat(catsy);
        for (int l = 0; l<4; l++)
        {
            tab[l]->makeSound();
            std::cout << "idea 0: " << (tab[l]->getBrainAddress())->getIdea(0) << std::endl; 
            std::cout << "idea 1: " << (tab[l]->getBrainAddress())->getIdea(1) << std::endl; 
        }
        
        std::cout << std::endl << YELLOW << "Checking deep copies" << std::endl;
        std::cout << "Doggos:" << RESET << std::endl;
        std::cout << &doggo << " " << tab[0] << " " << tab[1] << std::endl;
        std::cout << YELLOW << "Doggos' brains:" << RESET << std::endl;
        std::cout << doggo.getBrainAddress() << " " << tab[0]->getBrainAddress() << " " << tab[1]->getBrainAddress() << std::endl;
        std::cout << YELLOW << "Cats:" << RESET << std::endl;
        std::cout << &catsy << " " << tab[2] << " " << tab[3] << std::endl;
        std::cout << YELLOW << "Cats' brains:" << RESET << std::endl;
        std::cout << doggo.getBrainAddress() << " " << tab[2]->getBrainAddress() << " " << tab[3]->getBrainAddress() << std::endl;
        
        std::cout << std::endl << YELLOW << "Destructors" << RESET << std::endl;
        for (int l = 0; l<4; l++)
        {
            delete tab[l];
        }
    }
	return (0);
}
