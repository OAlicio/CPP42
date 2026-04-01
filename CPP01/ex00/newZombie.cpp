/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:32:03 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/20 16:01:38 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *newZombie;

	newZombie = new (std::nothrow) Zombie(name);
	if (newZombie == NULL)
		return NULL;
	return(newZombie);
}
