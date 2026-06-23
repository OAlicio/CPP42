/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:59:12 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/23 17:27:38 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
	private:
		std::string	fileName;
		std::ifstream bitFile;
		BitcoinExchange();

	public:
		~BitcoinExchange();
		BitcoinExchange(std::string file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		std::ifstream getFStream() const;
		void	Exchange();
};

#endif
