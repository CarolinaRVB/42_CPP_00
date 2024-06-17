/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:52 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/17 18:42:27 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string s;

	while (s.empty()){
		std::cout << std::endl << "> "  << GREEN << "Choose one option: 'ADD' 'SEARCH', 'EXIT': " << RESET;
		std::getline(std::cin, s);
		std::cout << std::endl;
		if (s.compare("EXIT") == 0)
			break ;
		else if (s.compare("ADD") == 0){
			Contacts contacts;
			contacts.info_setter(contacts);
			phonebook.add_info(contacts);
		}
		else if (s.compare("SEARCH") == 0){
			phonebook.print_contacts();
		}
		else
			std::cout << RED << "WARNING: Invalid option: try 'SEARCH', 'ADD', 'EXIT'" << RESET << std::endl;		
		s.clear();
	}
	std::cout << GREEN << "******  Closing Phonebook  ******" << RESET << std::endl;
	return 0;
}