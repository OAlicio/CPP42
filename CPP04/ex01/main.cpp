/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:57:22 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 12:03:03 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "========= Static Animal ==========" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	Dog dog3;

	dog3 = dog2;

	Cat cat1;
	Cat cat2(cat1);
	Cat cat3;

	cat3 = cat2;
	std::cout << "==================================" << std::endl;
	std::cout << "======= Zoo test as Animals ========" << std::endl;
	int numberAnimals;

	numberAnimals = 4;
	Animal *zoo[numberAnimals];
	for (int i = 0; i < numberAnimals; i++)
	{
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}
	std::cout << "\nMake Sound Method  " << std::endl;
	for (int i = 0; i < numberAnimals; i++)
	{
		zoo[i]->makeSound();
	}
	std::cout << "\n";
	for (int i = 0; i < numberAnimals; i++)
	{
		delete zoo[i];
	}

	std::cout << "\n======= Brain deep copy test ========" << std::endl;
	Cat cat;
	std::string idea = "Cat idea";
	cat.setIdea(0, idea);
	std::cout << "\n\"Original\" Cat Idea" << std::endl;
	std::cout << cat.getIdea(0) << std::endl;
	std::cout << "\n";
	Cat newCat(cat);
	std::cout << "\n\"Copy\" Cat Idea" << std::endl;
	std::cout << newCat.getAllIdeas()[0] << std::endl;
	std::cout << "\n";

	Dog dog;
	std::string idea2 = "Dog idea";
	dog.setIdea(0, idea2);
	std::cout << "\n\"Original\" Dog Idea" << std::endl;
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << "\n";
	Dog newDog(dog);
	std::cout << "\n\"Copy\" Dog Idea" << std::endl;
	std::cout << newDog.getAllIdeas()[0] << std::endl;
	std::cout << "\n";
	std::cout << "==================================" << std::endl;
}
