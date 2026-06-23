/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:48:30 by ofeverei          #+#    #+#             */
/*   Updated: 2026/05/29 10:36:53 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:
		static int	ids;
		const int	id;
		std::string type;
		std::string content;
	public:
		Data();
		Data(const std::string &type, const std::string &content);
		Data(const Data &other);
		Data &operator=(const Data &other);
		std::string getType() const;
		std::string	getContent() const;
		int			getId() const;
};

#endif
