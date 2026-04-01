/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:49:09 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/11 11:21:43 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &value);
		void	attack(const std::string &target);
		void	whoAmI();
};

#endif
