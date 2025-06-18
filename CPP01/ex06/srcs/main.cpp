/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:49 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/17 22:07:00 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <level>" << std::endl;
		return 1;
	}
	Harl harl;

	harl.complain(av[1]);
	return (0);
}