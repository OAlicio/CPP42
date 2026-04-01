/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:33:56 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 13:24:02 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): name("")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(std::string name): name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character Name constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = other;
	std::cout << "Character Copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &value)
{
	if (this != &value)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				manager.unSetMagic(this->inventory[i]);
				this->inventory[i] = NULL;
			}
			if (value.inventory[i])
			{
				this->inventory[i] = value.inventory[i]->clone();
				manager.setMagic(this->inventory[i]);
			}
			else
				this->inventory[i] = NULL;
		}
		this->name = value.name;
	}
	std::cout << "Character Copy Assignment operator called" << std::endl;
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria *m)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			manager.setMagic(m);
			this->inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
}

Character::~Character()
{
	std::cout << "Character Default destructor called" << std::endl;
}
