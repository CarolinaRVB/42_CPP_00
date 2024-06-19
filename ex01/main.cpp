/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:52 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/19 15:30:29 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"

int main(void)
{
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
			contacts.infoSetter();
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