/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:17 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/11 23:01:35 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contacts::get_info(Contacts &contacts){
	while (contacts.firstname.empty()){
		std::cout << "> " << BLUE << "Please enter first name: " << RESET;
		std::getline(std::cin, contacts.firstname);
	}
	while (contacts.lastname.empty()){
		std::cout  << "> " << BLUE << "Please enter last name: " << RESET;
		std::getline(std::cin, contacts.lastname);
	}
	while (contacts.nickname.empty()){
		std::cout << "> " << BLUE << "Please enter nickname: " << RESET;
		std::getline(std::cin, contacts.nickname);
	}
	while (contacts.secret.empty()){
		std::cout << "> " << BLUE << "Please enter secret: " << RESET;
		std::getline(std::cin, contacts.secret);
		
	}
	while (contacts.number.empty()){
		std::cout << "> " << BLUE << "Please enter number: " << RESET;
		std::getline(std::cin, contacts.number);
		for (int i = 0; contacts.number[i]; i++)
			if (!std::isdigit(contacts.number[i])){
				std::cout << RED << "WARNING: Number can only contain digits" << RESET << std::endl;
				contacts.number.clear();
				break ;
			}
	}
}