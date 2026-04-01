/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:46:49 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/23 16:54:05 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "============ DYNAMIC ALLOCATION USING newZombie() FUNCTION ============\n" << std::endl;
	Zombie	*ironMan;
	Zombie	*captainAmerica;
	Zombie	*spiderMan;

	ironMan = newZombie("Iron Man");
	captainAmerica = newZombie("Captain America");
	spiderMan = newZombie("Spider Man");

	ironMan->announce();
	captainAmerica->announce();
	spiderMan->announce();

	delete ironMan;
	delete captainAmerica;
	delete spiderMan;

	std::cout << "\n============ STATIC ALLOCATION USING randomChump() FUNCTION ============\n" << std::endl;
	randomChump("Super Man");
	randomChump("Batman");
	randomChump("Flash");
}
