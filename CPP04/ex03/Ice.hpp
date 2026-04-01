/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:09:26 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 17:56:54 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(std::string const &type);
		Ice(const Ice &other);
		Ice &operator=(const Ice &value);
		~Ice();
		std::string const &getType() const; //Returns the materia type
		Ice *clone() const;
		void use(ICharacter &target);
};

#endif
