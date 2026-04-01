/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:12:23 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/17 17:30:58 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), finish(0) {}

void	PhoneBook::exit() const {}

int		PhoneBook::getIndex() const
{
	return this->index;
}

bool	PhoneBook::isFinish() const
{
	return this->finish;
}

bool	PhoneBook::isValidName(std::string &str, bool isLastName) const
{
	size_t	i;
	bool	alpha;

	if (!std::isalpha(str[0]))
	{
		std::cout << "Name must be only alpha characters" << std::endl;
		return false;
	}
	else if (!std::isupper(str[0]) && !isLastName)
	{
		std::cout << "Name must start with a capital letter" << std::endl;
		return false;
	}
	alpha = true;
	i = 1;
	while (i < str.length())
	{
		if (std::isupper(str[i]) && alpha)
		{
			std::cout << "Capital letters should be separated with space" << std::endl;
			return false;
		}
		else if (!alpha && std::isupper(str[i]))
			alpha = true;
		if (!std::isalpha(str[i]) && !std::isspace(str[i]))
		{
			std::cout << "Name must be only alpha characters" << std::endl;
			return false;
		}
		if (std::isspace(str[i]))
		{
			alpha = false;
			if (!std::isupper(str[i + 1]))
			{
				std::cout << "Name must start with a capital letter after a space" << std::endl;
				return false;
			}
			else if(!std::isalpha(str[i - 1]))
			{
				std::cout << "Name must end with a lower character" << std::endl;
			}
		}
		i++;
	}
	return true;
}

bool	PhoneBook::isValidPhone(std::string &str) const
{
	std::string	fStr;

	if ((str[0] == '+' || str[0] == '9') && str.length() >= 9)
	{
		if (str[0] == '+')
		{
			if (str.substr(0, 4).compare("+244"))
			{
				std::cout << "Invalid angolan DDD" << std::endl;
				return false;
			}
			fStr = str.substr(4);
		}
		else
			fStr = str;
		if (fStr[0] != '9')
		{
			std::cout << "Phone Number must start with '9'" << std::endl;
			return false;
		}
		else if (fStr.length() != 9)
		{
			std::cout << "Phone Number must have only 9 digits excluding +244" << std::endl;
			return false;
		}
		else if (!this->isNumber(fStr))
		{
			std::cout << "Phone Number must be only digits" << std::endl;
			return false;
		}
	}
	else
	{
		if (str.length() >= 9 && str.length() <= 13 && str[0] != '9' )
			std::cout << "Phone Number must start with '9'" << std::endl;
		else if (str.length() < 9 || str.length() > 13)
			std::cout << "Phone Number must have 9 digits excluding +244" << std::endl;
		return false;
	}
	return true;
}

bool	PhoneBook::isNumber(std::string &str) const
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
		i++;
	}
	return true;
}

Contact	PhoneBook::getContact(int index) const
{
	return this->contacts[index];
}

std::string PhoneBook::resize_str(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return std::string(10 - str.length(), ' ') + str;
}

void	PhoneBook::displayContacts()
{
	int	i;
	int	len;

	i = 0;
	if (this->index > 7)
		len = 8;
	else
		len = this->index;
	std::cout << std::setw(10)
		<< std::setw(10) << resize_str("Index")
		<< std::setw(10) << "|" + resize_str("First Name")
		<< std::setw(10) << "|" + resize_str("Last Name")
		<< std::setw(10) << "|" + resize_str("Nick Name")
		<< std::endl;
	while(i < len)
	{
			std::cout << std::setw(10) << i
			<< std::setw(10) << "|" + resize_str(this->getContact(i).getName())
			<< std::setw(10) << "|" + resize_str(this->getContact(i).getLastName())
			<< std::setw(10) << "|" + resize_str(this->getContact(i).getNickName())
			<< std::endl;
		i++;
	}
}

void	PhoneBook::displayIdxContact()
{
	std::string	idxStr;
	std::string	selMsg;
	int			idx;
	int			i;

	if (this->finish)
		return ;
	if (this->index - 1 == 0)
		selMsg = "Select the contact index[";
	else
		selMsg = "Select the contact index[0-";
	i = 0;
	while (i < 1)
	{
		std::cout << selMsg << this->index - 1 << "]: ";
		std::getline(std::cin, idxStr);
		if (std::cin.fail())
		{
			this->finish = 1;
			break ;
		}
		else if (idxStr.empty() || !this->isNumber(idxStr)) //ADD VALIDATIONS HERE
		{
			std::cout << "Invalid index: " + idxStr << std::endl;
			continue ;
		}
		idx = std::atoi(idxStr.c_str());
		if (idx >= 0 && idx <= 7 && this->contacts[idx].getName().empty())
		{
			std::cout << "Contact at index: " << idxStr << " doesnt exist" << std::endl;
			continue ;
		}
		else if (idx < 0 || idx > 7)
		{
			std::cout << "Index " << idxStr << " out of bounds" << std::endl;
			continue ;
		}
		else
			this->getContact(idx).display();
		i++;
	}
}

std::string PhoneBook::getContactName()
{
	int	i;
	std::string	name;

	i = 0;
	if (this->finish)
		return "";
	while (i < 1)
	{
		std::cout << "First Name: ";
		std::getline(std::cin, name);
		if (std::cin.fail())
		{
			this->finish = 1;
			break ;
		}
		if (!this->isValidInput(name) || !isValidName(name, false))
		{
			std::cout << "Invalid input" << std::endl;
			continue ;
		}
		i++;
	}
	return name;
}

std::string PhoneBook::getContactLastName()
{
	int	i;
	std::string	lastName;

	i = 0;
	if (this->finish)
		return "";
	while (i < 1)
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, lastName);
		if (std::cin.fail())
		{
			this->finish = 1;
			break ;
		}
		if (!this->isValidInput(lastName) || !isValidName(lastName, true))
		{
			std::cout << "Invalid input" << std::endl;
			continue ;
		}
		i++;
	}
	return lastName;
}

std::string PhoneBook::getContactNickName()
{
	int	i;
	std::string	nickName;

	i = 0;
	if (this->finish)
		return "";
	while (i < 1)
	{
		std::cout << "Nick Name: ";
		std::getline(std::cin, nickName);
		if (std::cin.fail())
		{
			this->finish = 1;
			break ;
		}
		if (!this->isValidInput(nickName))
		{
			std::cout << "Invalid input" << std::endl;
			continue ;
		}
		i++;
	}
	return nickName;
}

std::string PhoneBook::getContactNumber()
{
	int	i;
	std::string	number;

	i = 0;
	if (this->finish)
		return "";
	while (i < 1)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, number);
		if (std::cin.fail())
		{
			this->finish = 1;
			break ;
		}
		if (!this->isValidInput(number) || !this->isValidPhone(number))
		{
			std::cout << "Invalid input" << std::endl;
			continue ;
		}
		i++;
	}
	return number;
}

std::string PhoneBook::getContactDarkestSecret()
{
	int	i;
	std::string	darkestSecret;

	i = 0;
	if (this->finish)
		return "";
	while (i < 1)
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.fail())
		{
			this->finish = 1;
			break ;
		}
		if (!this->isValidInput(darkestSecret))
		{
			std::cout << "Invalid input" << std::endl;
			continue ;
		}
		i++;
	}
	return darkestSecret;
}

bool	PhoneBook::isValidInput(std::string &str) const
{
	size_t	strLen;
	size_t	i;

	if (str.empty())
		return (false);
	i = 0;
	strLen = str.length();
	while (std::isspace(str[i]) && i < strLen)
		i++;
	if (i == strLen)
		return (false);
	return (true);
}

void	PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	name;
	std::string	contactName;
	std::string	phoneNumber;
	int	last;
	int	i;

	i = 0;
	firstName = this->getContactName();
	lastName = this->getContactLastName();
	phoneNumber = this->getContactNumber();
	name = firstName + " " + lastName;
	if (this->index > 8)
		last = 8;
	else
		last = this->index;
	while (i < last)
	{
		contactName = this->contacts[i].getName() + " " + this->contacts[i].getLastName();
		if (!contactName.compare(name) && !this->contacts[i].getNumber().compare(phoneNumber))
		{
			std::cout << "CONTACT ALREADY EXIST" << std::endl;
			return ;
		}
		i++;
	}
	this->contacts[this->index % 8].createContact(firstName, lastName,\
		this->getContactNickName(), phoneNumber, this->getContactDarkestSecret());
	if (!this->isFinish())
	{
		if (this->index > 7)
			std::cout << "Contact at index: " << this->index % 8 << " overrided" << std::endl;
		else
			std::cout << "Contact Added" << std::endl;
	}
	this->index++;
}

