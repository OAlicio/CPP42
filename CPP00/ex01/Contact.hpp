/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:12:21 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/26 16:46:26 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact();
		std::string	getName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getNumber() const;
		void		setName(std::string &name);
		void		setLastName(std::string &lastName);
		void		setNickName(std::string &nickName);
		void		setNumber(std::string &number);
		void		setDarkestSecret(std::string &darkestSecret);
		void		createContact(std::string name, std::string lastName, std::string nickName, std::string number, std::string darkestSecret);
		void		display();
};

#endif
