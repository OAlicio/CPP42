/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:22:14 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/26 15:54:23 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type) {}

const std::string &Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
