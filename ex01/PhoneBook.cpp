/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:39:30 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/11 22:58:42 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::get_next_index(PhoneBook &phonebook){
	phonebook.ncontact++;
	if (phonebook.ncontact == 8){
	{
		phonebook.oldest++;
		if (phonebook.oldest == 8)
			phonebook.oldest = 0;
		phonebook.ncontact = 0;
	}
	}
}

void	PhoneBook::print_contacts(const PhoneBook &phonebook){
	
	std::cout << YELLOW << "#############################################" << RESET << std::endl;
	std::cout << YELLOW << "#                                           #" << RESET << std::endl;
	std::cout << YELLOW << "#               Phone Book logs             #" << RESET << std::endl;
	std::cout << YELLOW << "#                  crebelo-                 #" << RESET << std::endl;
	std::cout << YELLOW << "#                                           #" << RESET << std::endl;
	std::cout << YELLOW << "#############################################" << RESET << std::endl;
	std::cout << CYAN << "|||||||||||||||||||||||||||||||||||||||||||||" << RESET << std::endl;
	std::cout << CYAN << "|  INDEX   |  First   |   Last   | Nickname |" << RESET << std::endl;
	std::cout << CYAN << "|||||||||||||||||||||||||||||||||||||||||||||" << RESET << std::endl;
	
	for (int i = 0; i < 8; i++) {
		std::cout << phonebook.index[i] << std::endl;
		std::cout << phonebook.contacts[i].firstname << std::endl;
		std::cout << phonebook.contacts[i].lastname << std::endl;	
	}
}

void	PhoneBook::add_info(const Contacts &contact, PhoneBook &phonebook){
	if (phonebook.empty){
		phonebook.empty = 0;
		phonebook.contacts[0] = contact;
		phonebook.oldest = 0 ;
	}
	else {
		get_next_index(phonebook);
		if (ncontact == 8){
			phonebook.contacts[0] = contact;
		}
		else{
			phonebook.contacts[phonebook.ncontact] = contact;
		}
	}
}
