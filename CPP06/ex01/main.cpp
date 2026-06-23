/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:38:03 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/03 17:11:02 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	{
		std::cout << "Using static object\n";
		Data data(".pdf", "Hello, world!");
		Data *ptr;
		ptr = Serializer::deserialize(Serializer::serialize(&data));
	
		std::cout << "Original object address: " << &data << std::endl;
		std::cout << "Deserialized object address: " << ptr << std::endl;
		std::cout << "Original Id: " << data.getId() << std::endl;
		std::cout << "Original Type: " << data.getType() << std::endl;
		std::cout << "Original Content: " << data.getContent() << std::endl;
		std::cout << "Deserialized Id: " << ptr->getId() << std::endl;
		std::cout << "Deserialized Type: " << ptr->getType() << std::endl;
		std::cout << "Deserialized Content: " << ptr->getContent() << std::endl;
	}
	{
		std::cout << "\nUsing Pointer to object\n";
		Data *data = new Data(".pdf", "Hello, world!");
		Data *ptr;
		uintptr_t raw;

		raw = Serializer::serialize(data);
		ptr = Serializer::deserialize(raw);
	
		std::cout << "Original object address: " << data << std::endl;
		std::cout << "Deserialized object address: " << ptr << std::endl;
		std::cout << "Original Id: " << data->getId() << std::endl;
		std::cout << "Original Type: " << data->getType() << std::endl;
		std::cout << "Original Content: " << data->getContent() << std::endl;
		std::cout << "Deserialized Id: " << ptr->getId() << std::endl;
		std::cout << "Deserialized Type: " << ptr->getType() << std::endl;
		std::cout << "Deserialized Content: " << ptr->getContent() << std::endl;
		delete data;
	}
	return (0);
}
