/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:12:05 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:55:03 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap clapTrap("OtherTrap");
	ClapTrap clap("ClapTrap");
	ClapTrap thisTrap(clap);

	std::cout << "\nAttack method" << std::endl;
	thisTrap.attack(clapTrap.getName());

	std::cout << "\nRepair method" << std::endl;
	thisTrap.beRepaired(1);

	std::cout << "\nTaking 1 hit damage" << std::endl;
	thisTrap.takeDamage(1);

	std::cout << "\nGetting tired with repair method" << std::endl;
	thisTrap.beRepaired(1);
	thisTrap.beRepaired(1);
	thisTrap.beRepaired(1);
	thisTrap.beRepaired(1);
	thisTrap.beRepaired(1);
	thisTrap.beRepaired(1);
	thisTrap.beRepaired(1);
	thisTrap.beRepaired(1);

	std::cout << "\nAttack method with no energy points left" << std::endl;
	thisTrap.attack(clapTrap.getName());

	std::cout << "\nRepair method with no energy points left" << std::endl;
	thisTrap.beRepaired(1000);

	std::cout << "\nTaking hit damage with no energy points left" << std::endl;
	thisTrap.takeDamage(1);

	std::cout << "\nTaking 1000 hit damage" << std::endl;
	clap.takeDamage(1000);

	std::cout << "\nAttack method with no hit points left" << std::endl;
	clap.attack(clapTrap.getName());

	std::cout << "\nRepair method with no hit points left" << std::endl;
	clap.beRepaired(1000);

	std::cout << "\nTaking hit damage while already dead" << std::endl;
	clap.takeDamage(1000);
	std::cout << "\n";
}
