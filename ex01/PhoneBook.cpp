/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:39:30 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/24 22:45:34 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	oldest_index = 0;
	contact_index = -1;
}

PhoneBook::~PhoneBook(){
}

// This function adds a contact information to the contacts object in the Contacts array
// of the PhoneBook class, which only contains 8 contacts max.
// Hence, through the modulo operator we can safely add a new contact to the next index.
void	PhoneBook::addInfo(const Contacts &contact){
	contact_index = (contact_index + 1) % 8;
	if (contact_index == 0)
		oldest_index = (oldest_index + 1) % 8;
	contacts[contact_index % 8] = contact;
}

// This function prints the contacts logs in 3 steps:
// 		1: Prints a header with a title and the columns names
//		2: Fills each row with the information of the existing contact
//			if the information is bigger than 10 characters, it shortens it
//		3: Asks the user to select a contact index and parses the input -> deals with 
//			wrong entries (above index 7 and bellow index 0), non numeric indexes,
//			non existing indexes
void	PhoneBook::printContacts(){
	std::cout << YELLOW << "#############################################\n" << RESET;
	std::cout << YELLOW << "#                                           #\n" << RESET;
	std::cout << YELLOW << "#       PhoneBook Contacts; crebelo-        #\n" << RESET;
	std::cout << YELLOW << "#                                           #\n" << RESET;
	std::cout << YELLOW << "#############################################\n" << RESET;
	std::cout << CYAN << "|||||||||||||||||||||||||||||||||||||||||||||\n" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Index" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "First" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Last" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Nickname" << "|\n" << RESET;
	std::cout << CYAN << "|||||||||||||||||||||||||||||||||||||||||||||\n" << RESET;

	for (int i = 0; (i < 8); i++){
		if (!contacts[i].getInfo(i))
			break ;}

	std::string index;
	std::cout << "\n";
	while (index.empty()){
		std::cout << YELLOW << "Choose a contact index from 0 to 7: " << RESET;
		std::getline(std::cin, index);
		if (index.length() != 1 || (index.length() == 1 && index.find_first_of("01234567") == std::string::npos)){
			std::cout << RED << "WARNING: Invalid option" << RESET;
			if (!contacts[0].getInfoIndexX()){
				std::cout << RED << " and phonebook is empty: exiting ...\n" << RESET;
				return ;
			}
			index.clear();
		}
		else if (!contacts[customStoi(index)].getInfoIndexX()){
			if (!contacts[0].getInfoIndexX()){
				std::cout << RED << "WARNING: Phonebook is empty: exiting ...\n" << RESET;
				return ;
			}
			std::cout << RED << "WARNING: Empty contact: try again ..." << RESET;
			index.clear();
		}
		std::cout << "\n";	
	}
	contacts[customStoi(index)].getInfoIndex(customStoi(index));
}
