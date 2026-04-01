/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:36:40 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:10:47 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
	this->name = "";
	this->ClapTrap::name = "_clap_name";
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap()
{
	this->ClapTrap::name = name + "_clap_name";
	this->name = name;
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Name Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &value)
{
	std::cout << "DiamondTrap Copy Assignment operator called" << std::endl;
	if (this != &value)
	{
		ClapTrap::operator=(value);
		this->name = value.name;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	if (this->hitPoint <= 0)
	{
		std::cout
			<< "DiamondTrap " + this->getName() + " is dead"
			<< std::endl;
		return ;
	}
	else if (!this->energyPoint)
	{
		std::cout
			<< "DiamondTrap " + this->getName() + " has no energy left to announce itself"
			<< std::endl;
		return ;
	}
	std::cout << "Name as Diamond: " << this->name << "\n" << "Name as Clap: " << this->ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
