/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:31:59 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/26 15:50:34 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL){}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack() const
{
	if (this->weapon)
		std::cout << this->name + " attacks with their " + this->weapon->getType()
			<< std::endl;
	else
		std::cout << this->name + " attacks with their fists" << std::endl;
}
