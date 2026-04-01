/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:08:37 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 13:26:29 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "MateriaManager.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		MateriaManager manager;
		AMateria *materias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &value);
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
		~MateriaSource();
};

#endif
