/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:18:51 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/23 16:56:39 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int		N;
	int		i;

	i = 0;
	std::cout << "======== 10 Goku's horde ========\n" << std::endl;
	N = 10;
	horde = zombieHorde(N, "Goku");

	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;

	std::cout << "\n======== 100 Goku's horde ========\n" << std::endl;
	N = 100;
	horde = zombieHorde(N, "Goku");

	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;

	std::cout << "\n======== 1000 Goku's horde ========\n" << std::endl;
	N = 1000;
	horde = zombieHorde(N, "Goku");

	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;


	std::cout << "\n======== 10 Saitama's horde ========\n" << std::endl;
	N = 10;
	horde = zombieHorde(N, "Saitama");

	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;

	std::cout << "\n======== 100 Saitama's horde ========\n" << std::endl;
	N = 100;
	horde = zombieHorde(N, "Saitama");

	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;

	std::cout << "\n======== 1000 Saitama's horde ========\n" << std::endl;
	N = 1000;
	horde = zombieHorde(N, "Saitama");

	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;
}
