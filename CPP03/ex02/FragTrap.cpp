/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:31:14 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:34:08 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->name = "";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &value)
{
	std::cout << "FragTrap Copy assignment constructor called" << std::endl;
	if (this != &value)
		ClapTrap::operator=(value);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->hitPoint <= 0)
	{
		std::cout
			<< "FragTrap " + this->getName() + " is dead"
			<< std::endl;
		return ;
	}
	else if (!this->energyPoint)
	{
		std::cout
			<< "FragTrap " + this->getName() + " has no energy left to request a high fives"
			<< std::endl;
		return ;
	}
	std::cout << "High Fives Guys!?" << std::endl;
}
