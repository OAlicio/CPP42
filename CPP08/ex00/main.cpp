/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:23:39 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/18 14:33:47 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	{
		std::cout << "Vector Test\n" << std::endl;
		std::vector<int> arr;
		arr.push_back(10);
		arr.push_back(20);
		arr.push_back(30);

		std::cout << "Element in Vector\n";
		try
		{
			std::vector<int>::iterator it = easyfind<std::vector<int> >(arr, 10);
			(void)it;
			std::cout << "Found" << std::endl;
		}
		catch(...)
		{
			std::cout << "Not Found\n";
		}
		std::cout << "\nElement not in Vector\n";
		try
		{
			std::vector<int>::iterator it = easyfind<std::vector<int> >(arr, 100);
			(void)it;
			std::cout << "Found" << std::endl;
		}
		catch(...)
		{
			std::cout << "Not Found\n";
		}
	}
	{
		std::cout << "\nList Test\n" << std::endl;
		std::list<int> arr;
		arr.push_back(10);
		arr.push_back(20);
		arr.push_back(30);

		std::cout << "Element in List\n";
		try
		{
			std::list<int>::iterator it = easyfind<std::list<int> >(arr, 10);
			(void)it;
			std::cout << "Found" << std::endl;
		}
		catch(...)
		{
			std::cout << "Not Found\n";
		}
		std::cout << "\nElement not in List\n";
		try
		{
			std::list<int>::iterator it = easyfind<std::list<int> >(arr, 100);
			(void)it;
			std::cout << "Found" << std::endl;
		}
		catch(...)
		{
			std::cout << "Not Found\n";
		}
	}
}
