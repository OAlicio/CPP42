/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:27:48 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/20 16:41:55 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): name("") {}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name + " from horde " + this->name + " were defeated" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
