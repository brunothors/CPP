/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:52:09 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/16 23:33:20 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << "Invalid number of zombies: " << N << std::endl;
		return 0;
	}
	
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; ++i){
		horde[i].setName(name);
		std::cout << "Unnamed zombie renamed: " << name << std::endl;
	}
	return horde;
}