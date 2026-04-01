/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:19:18 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 16:44:07 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaManager.hpp"

int MateriaManager::instances;
int MateriaManager::idx[100];
AMateria *MateriaManager::magics[100];

MateriaManager::MateriaManager()
{
	if (MateriaManager::instances == 0)
	{
		for (int i = 0; i < 100; i++)
		{
			MateriaManager::idx[i] = 0;
			MateriaManager::magics[i] = NULL;
		}
	}
	MateriaManager::instances++;
	std::cout << "MateriaManager Default constructor called" << std::endl;
}

MateriaManager::MateriaManager(const MateriaManager &other)
{
	(void)other;
	if (MateriaManager::instances == 0)
	{
		for (int i = 0; i < 100; i++)
		{
			MateriaManager::idx[i] = i + 1;
			MateriaManager::magics[i] = NULL;
		}
	}
	MateriaManager::instances++;
	std::cout << "MateriaManager Copy constructor called" << std::endl;
}

MateriaManager &MateriaManager::operator=(const MateriaManager &value)
{
	if (this != &value)
		(void)value;
	std::cout << "MateriaManager Assignment operator called" << std::endl;
	return *this;
}

void	MateriaManager::setIndex(int i)
{
	MateriaManager::idx[i] = i + 1;
}

void	MateriaManager::setMagic(AMateria *m)
{
	for (int i = 0; i < 100; i++)
	{
		if (MateriaManager::magics[i] == m)
			return ;
	}
	for (int i = 0; i < 100; i++)
	{
		if (!this->isAvailable(m) && !this->getIndex(i))
		{
			MateriaManager::magics[i] = m;
			this->setIndex(i);
			break ;
		}
	}
}

bool	MateriaManager::isAvailable(AMateria *m)
{
	for (int i = 0; i < 100; i++)
	{
		if (MateriaManager::magics[i] == m)
		{
			if (MateriaManager::idx[i] == 0)
				return false;
			return true;
		}
	}
	return false;
}

void	MateriaManager::unSetMagic(AMateria *m)
{
	for (int i = 0; i < 100; i++)
	{
		if (MateriaManager::magics[i] == m && this->getIndex(i))
		{
			delete MateriaManager::magics[i];
			MateriaManager::idx[i] = 0;
		}
	}
}

int	MateriaManager::getIndex(int i) const
{
	return MateriaManager::idx[i];
}

MateriaManager::~MateriaManager()
{
	if (MateriaManager::instances == 1)
	{
		for (int i = 0; i < 100; i++)
		{
			if (isAvailable(MateriaManager::magics[i]))
			{
				delete MateriaManager::magics[i];
				MateriaManager::idx[i] = 0;
			}
		}
	}
	MateriaManager::instances--;
	std::cout << "MateriaManager Default Destructor called" << std::endl;
}
