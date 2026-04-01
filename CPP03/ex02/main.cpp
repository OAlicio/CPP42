/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:12:05 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:37:27 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap other("FragTrap");
	FragTrap thisTrap(other);

	std::cout << "\nAttack method" << std::endl;
	thisTrap.attack("OtherTrap");

	std::cout << "\nRepair method" << std::endl;
	thisTrap.beRepaired(1);

	std::cout << "\nTaking 1 hit damage" << std::endl;
	thisTrap.takeDamage(1);

	std::cout << "\nSpecial method" << std::endl;
	thisTrap.highFivesGuys();

	std::cout << "\nTaking 1000 hit damage" << std::endl;
	thisTrap.takeDamage(1000);

	std::cout << "\nAttack method with no hit points left" << std::endl;
	thisTrap.attack("OtherTrap");

	std::cout << "\nRepair method with no hit points left" << std::endl;
	thisTrap.beRepaired(1000);

	std::cout << "\nTaking hit damage while already dead" << std::endl;
	thisTrap.takeDamage(1000);

	std::cout << "\nSpecial method with no hit points left" << std::endl;
	thisTrap.highFivesGuys();
	std::cout << "\n";
}
