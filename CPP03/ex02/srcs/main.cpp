/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:29:20 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:39:50 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap claptrap("foo");
    FragTrap fragtrap("bar");
    FragTrap fragtrap2("taz");

    claptrap.attack(fragtrap.getName());
    fragtrap.takeDamage(claptrap.getAttackDamage());

    fragtrap.beRepaired(5);
    fragtrap.attack(claptrap.getName());
    claptrap.takeDamage(fragtrap.getAttackDamage());
    claptrap.attack(fragtrap.getName());
    fragtrap.highFivesGuys();
    fragtrap2 = fragtrap;
    fragtrap2.attack(fragtrap.getName());

    return 0;

}