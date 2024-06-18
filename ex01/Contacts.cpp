/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:17 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/18 10:29:25 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contacts::info_setter(Contacts &contacts){
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

int	Contacts::info_getter(int index){
	if (firstname.empty())
		return (0);
	std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << index;
	if (firstname.length() > 10)
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << firstname.substr(0, 9) + ".";
	else
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << firstname;
	if (lastname.length() > 10)
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << lastname.substr(0, 9) + ".";
	else
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << lastname;
	if (lastname.length() > 10)
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << nickname.substr(0, 9) + ".";
	else
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << nickname << CYAN << "|" << RESET << std::endl;
	return (1);
}

int	Contacts::info_index_getter(int index){
	std::cout << std::endl << CYAN << "Index: " << RESET << index << std::endl;
	std::cout << CYAN << "First name: " << RESET << firstname << std::endl;
	std::cout << CYAN << "Last name: " << RESET << lastname << std::endl;
	std::cout << CYAN << "Nickname: " << RESET << nickname << std::endl;
	std::cout << CYAN << "Number: " << RESET << number << std::endl;
	std::cout << CYAN << "Darkest secret: " << RESET << secret << std::endl;	
	return (1);
}

int	Contacts::info_index_0_getter(){
	if (firstname.empty())
		return (0);	
	return (1);
}
