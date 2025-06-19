/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:14:29 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:39:48 by bnespoli         ###   ########.fr       */
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