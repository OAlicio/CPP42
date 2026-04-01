/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:14:03 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 14:23:26 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		this->materias[i] = NULL;
	std::cout << "MateriaSource Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for(int i = 0; i < 4; i++)
		this->materias[i] = NULL;
	*this = other;
	std::cout << "MateriaSource Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &value)
{
	if (this != &value)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->materias[i])
			{
				manager.unSetMagic(this->materias[i]);
				this->materias[i] = NULL;
			}
			if (value.materias[i])
			{
				this->materias[i] = value.materias[i]->clone();
				manager.setMagic(this->materias[i]);
			}
			else
				this->materias[i] = NULL;
		}
	}
	std::cout << "MateriaSource Default constructor called" << std::endl;
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i] == NULL)
		{
			manager.setMagic(materia);
			this->materias[i] = materia; 
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *newMateria;

	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
		{
			if (this->materias[i]->getType() == type)
			{
				newMateria = this->materias[i]->clone();
				manager.setMagic(newMateria);
				return newMateria;
			}
		}
	}
	return 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
}
