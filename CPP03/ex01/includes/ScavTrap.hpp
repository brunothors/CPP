/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:14:29 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 22:01:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap();

        ScavTrap &operator=(ScavTrap const &rhs);

        void attack(std::string const &target);
        void guardGate();
};

#endif