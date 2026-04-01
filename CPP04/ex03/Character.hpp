/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:26:09 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 13:07:14 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "MateriaManager.hpp"

class Character: public ICharacter
{
	private:
		MateriaManager manager;
		AMateria *inventory[4];
		std::string name;
	
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &value);
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		~Character();
};

#endif
