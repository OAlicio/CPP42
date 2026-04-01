/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:12:16 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/10 17:43:46 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

std::string	Contact::getName() const
{
	return this->firstName;
}

std::string	Contact::getLastName() const
{
	return this->lastName;
}

std::string	Contact::getNickName() const
{
	return this->nickName;
}

std::string	Contact::getNumber() const
{
	return this->phoneNumber;
}

void	Contact::setName(std::string &name)
{
	this->firstName = name;
}

void	Contact::setLastName(std::string &lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(std::string &nickName)
{
	this->nickName = nickName;
}

void	Contact::setNumber(std::string &number)
{
	this->phoneNumber = number;
}

void	Contact::setDarkestSecret(std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

void	Contact::createContact(std::string name, std::string lastName, std::string nickName, std::string number, std::string darkestSecret)
{
	this->setName(name);
	this->setLastName(lastName);
	this->setNickName(nickName);
	this->setNumber(number);
	this->setDarkestSecret(darkestSecret);
}

void	Contact::display()
{
	std::cout << "First Name: " + this->getName() + "\nLast Name: " + this->getLastName() + "\nNick Name: " + this->getNickName() + "\nPhone Number: " + this->getNumber() << std::endl;
}
