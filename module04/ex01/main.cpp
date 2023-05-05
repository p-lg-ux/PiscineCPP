/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:52:35 by pgros             #+#    #+#             */
/*   Updated: 2023/05/05 16:07:06 by pgros            ###   ########.fr       */
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
        i->makeSound(); //will output the cat sound!
        meta->makeSound();

        delete meta;
        delete i;
    }
	return (0);
}

/*
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

# define GREY   "\x1b[30m"
# define RED    "\x1b[31m"
# define GREEN  "\x1b[32m"
# define BLUE   "\x1b[34m"
# define PURPLE "\x1b[35m"
# define CYAN   "\x1b[36m"
# define WHITE  "\x1b[37m"

int main(void)
{
    std::cout << YELOW << "Creating constructor for the class Animal(void), Cat(luna), Dog(reglise) !" << END << std::endl;
    Animal *animal = new Animal();
    Animal *reglise = new Dog("reglise");
    Animal *luna = new Cat("luna");
    std::cout << GREEN << "called the function makeSound for the class ! (Animal, Cat, Dog)" << END << std::endl;
    animal->makeSound();
    luna->makeSound();
    reglise->makeSound();
    std::cout << BLUE << "called type for the Animal("<< animal->getType() <<") !" << END << std::endl;
    std::cout << BLUE << "called type for the Cat("<< luna->getType() <<") !" << END << std::endl;
    std::cout << BLUE << "called type for the Dog("<< reglise->getType() <<") !" << END << std::endl;
    std::cout << RED << "destructor called for the class !(Animal, Cat, Dog)" << END << std::endl;
    delete animal;
    delete luna;
    delete reglise;
    std::cout << YELOW << "creating WrongAnimal and WrongCat testing the class is not virtual void makeSound()"<< END << std::endl;
    WrongAnimal *wanimal = new WrongCat();
    WrongCat *wcat = new WrongCat("luna");
    std::cout << GREEN << "WrongAnimal and WrongCat called getType and makeSound " << END << std::endl;
    std::cout << "WrongAnimal type " << wanimal->getType() << " makeSound "; wanimal->makeSound();
    std::cout << "WrongCat type " << wcat->getType() << " makeSound "; wcat->makeSound();
    std::cout << RED << "destructor called for the class !(WrongAnimal, WrongCat)" << END << std::endl;
    delete wanimal;
    delete wcat;
    return (0);
}*/