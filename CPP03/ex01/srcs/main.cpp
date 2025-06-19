/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:29:20 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 22:01:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap("foo");
    ScavTrap scavtrap("bar");
    ScavTrap scavtrap2("baz");
    ScavTrap scavtrap3(scavtrap);

    claptrap.attack(scavtrap.getName());
    scavtrap.takeDamage(claptrap.getAttackDamage());

    scavtrap.beRepaired(5);
    scavtrap.attack(claptrap.getName());
    claptrap.takeDamage(scavtrap.getAttackDamage());
    claptrap.attack(scavtrap.getName());
    scavtrap.guardGate();
    scavtrap2 = scavtrap;
    scavtrap2.attack(scavtrap.getName());

    return 0;

}