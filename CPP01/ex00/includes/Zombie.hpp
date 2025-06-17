/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:13:32 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/16 22:34:33 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();
	
		void announce();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif