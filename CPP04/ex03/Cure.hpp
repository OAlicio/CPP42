/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:03:27 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/13 17:58:10 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(std::string const &type);
		Cure(const Cure &other);
		Cure &operator=(const Cure &value);
		~Cure();
		std::string const &getType() const; //Returns the materia type
		Cure *clone() const;
		void use(ICharacter &target);
};

#endif
