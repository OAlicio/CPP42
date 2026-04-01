/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:24:57 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/20 17:19:39 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void			setName(std::string name);
		void			announce();
};

Zombie	*zombieHorde(int N, std::string name);

#endif
