/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:52 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/11 23:00:55 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string s;

	while (s.empty()){
		Contacts contacts;
		std::cout << "> ";
		std::getline(std::cin, s);
		if (s.compare("EXIT") == 0)
			break ;
		else if (s.compare("ADD") == 0){
			contacts.get_info(contacts);
			phonebook.add_info(contacts, phonebook);
		}
		else if (s.compare("SEARCH") == 0){
			phonebook.print_contacts(phonebook);
		}
		else
			std::cout << RED << "WARNING: Invalid option: try 'SEARCH', 'ADD', 'EXIT'" << RESET << std::endl;		
		s.clear();
	}
	// phonebook.print_contacts(phonebook);
	
	return 0;
}