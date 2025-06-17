/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:26:35 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/16 22:28:38 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie* zombie = newZombie("heapZombie");
	zombie->announce();
	
	randomChump("stackZombie");
	
	delete zombie; 
	return 0;
}