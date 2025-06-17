/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:56:30 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/16 23:30:01 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 5;
	std::string name = "bob";

	Zombie *horde = zombieHorde(N, name);
	if (horde) {
		for (int i = 0; i < N; ++i) {
			horde[i].announce();
		}
		delete[] horde;
	}

	return 0;
}