/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:34:20 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 20:59:58 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	private:
		std::string ideas_[100];

	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &other);

		std::string getIdea(unsigned int index) const;
		void setIdea(unsigned int index, const std::string &idea);
};

#endif