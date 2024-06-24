/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:52 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/24 22:49:25 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1){
		std::cout << RED << "ERROR: no arguments allowed" << RESET << std::endl;
		return (1);
	}

	PhoneBook	phonebook;
	std::string	s;

	while (s.empty()){
		std::cout << std::endl << "> "  << GREEN << "Choose one option: 'ADD' 'SEARCH', 'EXIT': " << RESET;
		std::getline(std::cin, s);
		std::cout << "\n";
		if (s.compare("EXIT") == 0)
			break ;
		else if (s.compare("ADD") == 0){
			Contacts contacts;
			contacts.setInfo();
			phonebook.addInfo(contacts);
		}
		else if (s.compare("SEARCH") == 0){
			phonebook.printContacts();
		}
		else
			std::cout << RED << "WARNING: Invalid option: try 'SEARCH', 'ADD', 'EXIT'\n" << RESET;		
		s.clear();
	}
	std::cout << GREEN << "******  Closing Phonebook  ******\n" << RESET;
	return (0);
}