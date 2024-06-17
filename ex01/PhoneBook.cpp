/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:39:30 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/17 19:08:07 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::get_next_index(){
	ncontact++;
	if (ncontact == 8){
		oldest++;
		if (oldest == 8)
			oldest = 0;
		ncontact = 0;
	}
}

void	PhoneBook::print_contacts(){
	
	
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

	for (int i = 0; (i <= ncontact && i < 8); i++){
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << i;
		contacts[i].info_getter();}
	
	std::string index;
	std::cout << std::endl;
	while (index.empty()){
		std::cout << YELLOW << "Choose a contact index from 0 to 7: " << RESET;
		std::getline(std::cin, index);
		if (index.length() != 1 || (index.length() == 1 && index.find_first_of("01234567") == std::string::npos)
			|| (index.length() == 1 && !contacts[stoi(index)].info_index_getter())){
			std::cout << RED << "WARNING: Invalid option" << RESET;
			if (!contacts[0].info_index_getter()){
				std::cout << RED << " -> No contacts in Phonebook!" << RESET << std::endl;
				break ;
			}
			else
				std::cout << std::endl;
			index.clear();
		}
	}

}

void	PhoneBook::add_info(const Contacts &contact){
	if (empty){
		empty = 0;
		contacts[0] = contact;
		oldest = 0;
	}
	else {
		get_next_index();
		if (ncontact == 8)
			contacts[0] = contact;
		else
			contacts[ncontact] = contact;
	}
}
