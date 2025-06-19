/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:29:20 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:39:37 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("foo");
    ClapTrap claptrap2("bar");

    claptrap1.setAttackDamage(4);
    claptrap2.setAttackDamage(10);  

    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(claptrap1.getAttackDamage());

    claptrap2.beRepaired(5);
    claptrap2.attack(claptrap1.getName());
    claptrap1.takeDamage(claptrap2.getAttackDamage());
    claptrap1.attack(claptrap2.getName());

    return 0;

}