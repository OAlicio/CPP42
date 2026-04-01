/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:29:38 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:35:27 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	name = "";
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &value)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &value)
		ClapTrap::operator=(value);
	return *this;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap Name constructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hitPoint <= 0)
	{
		std::cout
			<< "ScavTrap " + this->getName() + " is dead"
			<< std::endl;
		return ;
	}
	else if (!this->energyPoint)
	{
		std::cout
			<< "ScavTrap " + this->getName() + " has no energy left to attack "
			<< target << std::endl;
		return ;
	}
	std::cout
		<< "ScavTrap " + this->getName() + " attack "
		<< target << ", causing "
		<< this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint--;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->hitPoint <= 0)
	{
		std::cout
			<< "ScavTrap " + this->getName() + " is dead"
			<< std::endl;
		return ;
	}
	else if (!this->energyPoint)
	{
		std::cout
			<< "ScavTrap " + this->getName() + " has no energy left to guard the gate"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " + this->getName() + " is in gate keeper mode" << std::endl;
}
