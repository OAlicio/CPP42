/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeManager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:40:11 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/29 12:49:38 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEMANAGER_HPP
# define TYPEMANAGER_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>
# include <iostream>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
