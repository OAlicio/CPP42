/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:27:48 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/23 16:53:19 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie()
{
	std::cout << this->name + " were defeated" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
