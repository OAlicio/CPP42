/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:02:59 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:49:50 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
		this->name = value.getName();
	return *this;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return this->name;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hitPoint <= 0)
	{
		std::cout
			<< "ClapTrap " + this->getName() + " is dead"
			<< std::endl;
		return ;
	}
	else if (!this->energyPoint)
	{
		std::cout
			<< "ClapTrap " + this->getName() + " has no energy left to attack "
			<< target << std::endl;
		return ;
	}
	std::cout
		<< "ClapTrap " + this->getName() + " attack "
		<< target << ", causing "
		<< this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0)
	{
		std::cout
			<< "ClapTrap " + this->getName() + " is dead"
			<< std::endl;
		return ;
	}
	else if (this->energyPoint == 0)
	{
		std::cout
			<< "ClapTrap " + this->getName() + " has no energy left to heal itself "
			<< std::endl;
		return ;
	}
	std::cout
		<< "ClapTrap " + this->getName() + " gained "
		<< amount << " hit points!" << std::endl;
	this->hitPoint += amount;
	this->energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint <= 0)
	{
		std::cout
			<< "ClapTrap " + this->getName() + " is dead"
			<< std::endl;
		return ;
	}
	std::cout
		<< "ClapTrap " + this->getName() + " loses "
		<< amount << " hit points!" << std::endl;
	this->hitPoint -= amount;
}
