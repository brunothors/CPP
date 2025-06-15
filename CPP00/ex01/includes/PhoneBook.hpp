/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 20:19:29 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/14 23:52:06 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		size_t	_index;
		size_t	_length;
		Contact	_contacts[8];
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		Contact getContact(int index) const;
        int getLength() const;
        int getIndex() const;
        void setContact(Contact contact);
        void setLength(int length);
        void setIndex(int index);
        void addContact();
        void searchContact();
};

#endif