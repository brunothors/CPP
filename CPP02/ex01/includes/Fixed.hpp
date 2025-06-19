/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:41:57 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/18 19:44:40 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_fBits = 8;
	public:
		Fixed();
		Fixed(Fixed const &other);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		Fixed &operator=(Fixed const &other);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &oS, Fixed const &other);

#endif