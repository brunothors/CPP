/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:30:01 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 22:03:35 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal {
	protected:
		std::string type_;
	
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &other);

		std::string getType() const;
		void setType(const std::string &type);
		
		virtual void makeSound() const = 0;
		virtual Brain* getBrain() const = 0;

};

#endif