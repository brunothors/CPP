/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:59:53 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:39:51 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FlagTrap default constructor called." << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
    std::cout << "FlagTrap " << name << " constructor called." << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
    std::cout << "FlagTrap copy constructor called." << std::endl;
    *this = src;
}

FragTrap::~FragTrap() {
    std::cout << "FlagTrap destructor called." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    std::cout << "FlagTrap assignment operator called." << std::endl;
    if (this != &rhs) {
        setName(rhs.getName());
        setHitPoints(rhs.getHitPoints());
        setEnergyPoints(rhs.getEnergyPoints());
        setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FlagTrap " << getName() << " is requesting a high five!" << std::endl;
}