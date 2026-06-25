/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:59:12 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/25 16:48:14 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <climits>
# include <cmath>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::string	fileName;
		std::ifstream bitFile;
		BitcoinExchange();

	public:
		std::map<std::string, double> m;
		~BitcoinExchange();
		BitcoinExchange(const std::string file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		const std::string getFStream() const;
		void	loadDb();
		void	exchange(const std::string file);
		void	open(const std::string file);
};

#endif
