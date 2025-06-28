/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:12:36 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 20:30:50 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "Animal type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << "Dog type: " << j->getType() << std::endl;
	j->makeSound();
	std::cout << "Cat type: " << i->getType() << std::endl;
	i->makeSound();
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
		
	delete meta;
	delete j;
	delete i;
	delete wrongCat;

	return 0;
}