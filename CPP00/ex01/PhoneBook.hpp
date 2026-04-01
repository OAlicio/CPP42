/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:12:26 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/17 17:06:47 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{

	private:

		int			index;
		bool		finish;
		Contact		contacts[8];

	public:

		PhoneBook();
		std::string	getContactName();
		std::string	getContactNumber();
		std::string	getContactLastName();
		std::string	getContactNickName();
		std::string	getContactDarkestSecret();
		std::string resize_str(std::string str);
		Contact		getContact(int index) const;
		bool		isFinish() const;
		bool		isNumber(std::string &str) const;
		bool		isValidPhone(std::string &str) const;
		bool		isValidInput(std::string &str) const;
		bool		isValidName(std::string &str, bool isLastName) const;
		int			getIndex() const;
		void		exit() const;
		void		addContact();
		void		displayContacts();
		void		displayIdxContact();

};

#endif

