/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:12:05 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:28:25 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	dTrap("DiamondTrap");
	DiamondTrap thisTrap(dTrap); 

	std::cout << "\nAttack method" << std::endl;
	thisTrap.attack("OtherTrap");

	std::cout << "\nRepair method" << std::endl;
	thisTrap.beRepaired(1);

	std::cout << "\nTaking 1 hit damage" << std::endl;
	thisTrap.takeDamage(1);

	std::cout << "\nSpecial method" << std::endl;
	thisTrap.whoAmI();

	std::cout << "\nTaking 1000 hit damage" << std::endl;
	thisTrap.takeDamage(1000);

	std::cout << "\nAttack method with no hit points left" << std::endl;
	thisTrap.attack("OtherTrap");

	std::cout << "\nRepair method with no hit points left" << std::endl;
	thisTrap.beRepaired(1000);

	std::cout << "\nTaking hit damage while already dead" << std::endl;
	thisTrap.takeDamage(1000);

	std::cout << "\nSpecial method with no hit points left" << std::endl;
	thisTrap.whoAmI();
	std::cout << "\n";
}
