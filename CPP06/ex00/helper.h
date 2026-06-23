/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:07:40 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/03 17:08:18 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "ScalarConverter.hpp"

void		convertBasef(const std::string &value);
void		convertBased(const std::string &value);
void		convertBasei(const std::string &value);
void		convertBasec(const std::string &value);
std::string	trim(const std::string &str);

#endif 
