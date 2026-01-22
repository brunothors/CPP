/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:33:56 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/22 18:33:57 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

int main() {
    Base *obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;

    return (0);
}