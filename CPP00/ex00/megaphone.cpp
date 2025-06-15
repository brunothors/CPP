/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:12:27 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/14 19:29:10 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE NOISE *" << std::endl;
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0;av[i][j]; j++)
			std::cout << (char) std::toupper(av[i][j]);
	}
	std::cout << std::endl;
}