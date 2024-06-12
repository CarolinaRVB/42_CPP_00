/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:39:30 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/12 12:56:22 by crebelo-         ###   ########.fr       */
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
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Index" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "First" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Last" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Nickname" << "|" << RESET << std::endl;
	std::cout << CYAN << "|||||||||||||||||||||||||||||||||||||||||||||" << RESET << std::endl;

	for (int i = 0; (i < 8 && !contacts[i].firstname.empty()); i++) {
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << phonebook.index[i];
		if (contacts[i].firstname.length() > 10)
			std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << contacts[i].firstname.substr(0, 9) + ".";
		else
			std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << contacts[i].firstname;
		if (contacts[i].lastname.length() > 10)
			std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << contacts[i].lastname.substr(0, 9) + ".";
		else
			std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << contacts[i].lastname;
		if (contacts[i].lastname.length() > 10)
			std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << contacts[i].nickname.substr(0, 9) + ".";
		else
			std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << contacts[i].nickname << CYAN << "|" << RESET << std::endl;
	}
	
	std::string index;
	std::cout << std::endl;
	while (index.empty()){
		std::cout << YELLOW << "Choose a contact index from 0 to 7: " << RESET;
		std::getline(std::cin, index);
		if (index.length() != 1 || (index.length() == 1 && index.find_first_of("01234567") == std::string::npos)
			|| (index.length() == 1 && contacts[stoi(index)].firstname.empty())){
			std::cout << RED << "WARNING: Invalid option" << RESET;
			if (contacts[0].firstname.empty()){
				std::cout << RED << " -> No contacts in Phonebook!" << RESET << std::endl;
				break ;
			}
			else
				std::cout << std::endl;
			index.clear();
		}
		else{
			std::cout << std::endl << CYAN << "Index: " << RESET << index << std::endl;
			std::cout << CYAN << "First name: " << RESET << contacts[stoi(index)].firstname << std::endl;
			std::cout << CYAN << "Last name: " << RESET << contacts[stoi(index)].lastname << std::endl;
			std::cout << CYAN << "Nickname: " << RESET << contacts[stoi(index)].nickname << std::endl;
			std::cout << CYAN << "Number: " << RESET << contacts[stoi(index)].number << std::endl;
			std::cout << CYAN << "Darkest secret: " << RESET << contacts[stoi(index)].secret << std::endl;	
		}
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
