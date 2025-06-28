/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:12:36 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 21:49:28 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Dog* dog = new Dog();
	Cat* cat = new Cat();
	
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

	std::cout << "------------------- ZOO -------------------" << std::endl;
    const Animal *zoo[4];

    std::cout << "------------------- DOGS -------------------" << std::endl;
    for (size_t i = 0; i < 2; i += 1) {
      zoo[i] = new Dog();
      std::cout << std::endl;
    }

    std::cout << "------------------- CATS -------------------" << std::endl;
    for (size_t i = 2; i < 4; i += 1) {
      zoo[i] = new Cat();
      std::cout << std::endl;
    }
	
	std::cout << "------------------ DEEP COPY ADRESS ----------------" << std::endl;
	Cat* adress1 = new Cat();
	Cat* adress2 = new Cat(*adress1);
	adress1->printAdress();
	adress2->printAdress();
	delete adress1;
	delete adress2;
	
    std::cout << "---------------- DELETE ZOO ---------------" << std::endl;
    for (size_t i = 0; i < 4; i += 1) {
      delete zoo[i];
    }
    std::cout << "--------------- ZOO DELETED ---------------" << std::endl;
    std::cout << std::endl;
	
    return (0);
}