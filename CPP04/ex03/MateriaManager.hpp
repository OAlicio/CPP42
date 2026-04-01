/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaManager.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:16:14 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/16 14:31:02 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAMANAGER_HPP
# define MATERIAMANAGER_HPP

# include "AMateria.hpp"

class MateriaManager
{
	private:
		static int instances;
		static int idx[100];
		static AMateria *magics[100];

	public:
		MateriaManager();
		MateriaManager(const MateriaManager &other);
		MateriaManager &operator=(const MateriaManager &value);
		~MateriaManager();
		void setIndex(int i);
		void setMagic(AMateria *m);
		void unSetMagic(AMateria *m);
		bool isAvailable(AMateria *m);
		int	getIndex(int i) const;
};

#endif
