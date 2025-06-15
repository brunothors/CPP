/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 20:19:31 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/14 22:38:52 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
	private:
		std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phone;
        std::string _darkestSecret;
	
	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string darkestSecret);
		~Contact();


		std::string getFirstName() const;
    	std::string getLastName() const;
    	std::string getNickname() const;
    	std::string getPhone() const;
    	std::string getDarkestSecret() const;
		
		void setFirstName(std::string firstName);
    	void setLastName(std::string lastName);
    	void setNickname(std::string nickname);
    	void setPhone(std::string phone);
    	void setDarkestSecret(std::string darkestSecret);

		void	showPreInfo();
		void	displayInfo();
};

#endif