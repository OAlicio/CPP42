/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:57:22 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/12 16:31:01 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
		std::cout << "========= Dynamic Animal ==========" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << "========= Wrong Animal ==========" << std::endl;
		const WrongAnimal* meta2 = new WrongAnimal();
		const WrongAnimal* i2 = new WrongCat();
		std::cout << i2->getType() << " " << std::endl;
		i2->makeSound(); //will not output the cat sound!
		meta2->makeSound();

		std::cout << "========= Destruction ==========" << std::endl;
		delete meta;
		delete j;
		delete i;
		delete meta2;
		delete i2;
		std::cout << "==================================" << std::endl;
}
