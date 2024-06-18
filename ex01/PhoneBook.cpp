/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:39:30 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/18 19:21:28 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::getNextIndex(){
	ncontact++;
	if (ncontact == 8){
		oldest++;
		if (oldest == 8)
			oldest = 0;
		ncontact = 0;
	}
}

void	PhoneBook::printContacts(){
	std::cout << YELLOW << "#############################################\n" << RESET;
	std::cout << YELLOW << "#                                           #\n" << RESET;
	std::cout << YELLOW << "#               Phone Book logs             #\n" << RESET;
	std::cout << YELLOW << "#                  crebelo-                 #\n" << RESET;
	std::cout << YELLOW << "#                                           #\n" << RESET;
	std::cout << YELLOW << "#############################################\n" << RESET;
	std::cout << CYAN << "|||||||||||||||||||||||||||||||||||||||||||||\n" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Index" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "First" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Last" << RESET;
	std::cout << CYAN << "|" << std::right << std::setw(10) << "Nickname" << "|\n" << RESET;
	std::cout << CYAN << "|||||||||||||||||||||||||||||||||||||||||||||\n" << RESET;

	for (int i = 0; (i < 8); i++){
		if (!contacts[i].infoGetter(i))
			break ;}

	std::string index;
	std::cout << "\n";
	while (index.empty()){
		std::cout << YELLOW << "Choose a contact index from 0 to 7: " << RESET;
		std::getline(std::cin, index);
		if (index.length() != 1 || (index.length() == 1 && index.find_first_of("01234567") == std::string::npos)){
			std::cout << RED << "WARNING: Invalid option" << RESET;
			if (!contacts[0].infoIndexXChecker()){
				std::cout << RED << " and phonebook is empty: exiting ...\n" << RESET;
				return ;
			}
			index.clear();
		}
		else if (!contacts[stoi(index)].infoIndexXChecker()){
			if (!contacts[0].infoIndexXChecker()){
				std::cout << RED << "WARNING: Phonebook is empty: exiting ...\n" << RESET;
				return ;
			}
			std::cout << RED << "WARNING: Empty contact: try again ..." << RESET;
			index.clear();
		}
		std::cout << "\n";	
	}
	contacts[stoi(index)].infoIndexGetter(stoi(index));
}

void	PhoneBook::addInfo(const Contacts &contact){
	if (empty){
		empty = 0;
		contacts[0] = contact;
		oldest = 0;
	}
	else {
		getNextIndex();
		if (ncontact == 8)
			contacts[0] = contact;
		else
			contacts[ncontact] = contact;
	}
}
