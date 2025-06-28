/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:12:36 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 22:05:26 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	// const AAnimal* Animal = new AAnimal(); 
	
	std::cout << "----------xx----------xx----------xx----------" << std::endl;

    for (int i = 0; i <= 100; i++) {
        cat->getBrain()->setIdea(i, "sleep on keyboard");
        dog->getBrain()->setIdea(i, "get my tail");
    }

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << cat->getType() << " is thinking about: "<< cat->getBrain()->getIdea(i) << std::endl;
        std::cout << dog->getType() << " is thinking about: "<< dog->getBrain()->getIdea(i) << std::endl;
    }

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

    std::cout << cat->getType() << " is thinking about: "<< cat->getBrain()->getIdea(100) << std::endl;
    std::cout << dog->getType() << " is thinking about: "<< dog->getBrain()->getIdea(100) << std::endl;

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

    delete cat;
    delete dog;

	std::cout << "----------xx----------xx----------xx----------" << std::endl;
	
    return (0);
}