/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:39:53 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/01 10:37:37 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeManager.h"

Base *generate(void)
{
	int rand = std::rand() % 3;
	if (rand == 0)
		return new A();
	else if (rand == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "Its a A Class object" << std::endl;
		return ;
	}
	b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "Its a B Class object" << std::endl;
		return ;
	}
	c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "Its a C Class object" << std::endl;
		return ;
	}
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Its a A Class object" << std::endl;
		return ;
	}
	catch(...) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Its a B Class object" << std::endl;
		return ;
	}
	catch(...) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Its a C Class object" << std::endl;
		return ;
	}
	catch(...) {}
}

