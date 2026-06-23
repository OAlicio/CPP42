/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:53:36 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/03 17:26:28 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeManager.h"

int main()
{
	std::srand(time(NULL)); //Populate the seeds for rand() func
	Base *p = generate();	
	Base *rand = generate();
	A a;
	B b;
	C c;
	identify(a);
	identify(b);
	identify(c);
	std::cout << "\nIdentify from generate method\n\n";
	identify(p);
	identify(*rand);
	delete p;
	delete rand;
	return (0);
}
