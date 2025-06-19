/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:29:18 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 22:01:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    private:
        std::string  _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string const &name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap();

        ClapTrap &operator=(ClapTrap const &rhs);

        void setName(std::string const &name);
        void setHitPoints(unsigned int const hitPoints);
        void setEnergyPoints(unsigned int const energyPoints);
        void setAttackDamage(unsigned int const attackDamage);

        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;

        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif