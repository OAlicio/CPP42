/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:32:59 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/24 17:47:07 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <iostream>
# include <fstream>
# include <string>

std::string	replace(std::string &readStr, std::string &match, std::string &toReplace, size_t &pos);
void	readFromFile(std::ifstream &readFile, std::string &finalStr, const char **av);
void	replacer(const char **av);

#endif
