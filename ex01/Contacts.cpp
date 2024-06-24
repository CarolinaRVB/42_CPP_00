/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:17 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/24 22:44:00 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// This function is responsible for obtaining the inputs, parsing them and storing them in the object contacts
// of the class Contacts. It's the setter function for private information
void Contacts::setInfo(){
	while (m_firstname.empty() || checkNamesValidity(m_firstname, "Firstname")){
		std::cout << "> " << BLUE << "Please enter first name: " << RESET;
		std::getline(std::cin, m_firstname);
	}
	while (m_lastname.empty() || checkNamesValidity(m_lastname, "Lastname")){
		std::cout  << "> " << BLUE << "Please enter last name: " << RESET;
		std::getline(std::cin, m_lastname);
	}
	while (m_nickname.empty() || checkNamesValidity(m_nickname, "Nickname")){
		std::cout << "> " << BLUE << "Please enter nickname: " << RESET;
		std::getline(std::cin, m_nickname);
	}
	while (m_secret.empty() ){
		std::cout << "> " << BLUE << "Please enter secret: " << RESET;
		std::getline(std::cin, m_secret);
		if (checkIfOnlySpaces(m_secret)){
			std::cout << RED << "WARNING: Secret can only contain alphanumerical characters\n" << RESET;
			m_secret.clear();
		}
	}
	while (m_number.empty()){
		std::cout << "> " << BLUE << "Please enter number: " << RESET;
		std::getline(std::cin, m_number);
		for (int i = 0; m_number[i]; i++)
			if (!std::isdigit(m_number[i])){
				std::cout << RED << "WARNING: Number can only contain digits\n" << RESET;
				m_number.clear();
				break ;
			}
	}
}

// This function is used in the printContacts function and serves to check if each contacts variable has more
// than 10 characters, if so it prints the shortened version, otherwise it prints the original
int	Contacts::getInfo(int index){
	if (m_firstname.empty())
		return (0);
	std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << index;
	if (m_firstname.length() > 10)
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << m_firstname.substr(0, 9) + ".";
	else
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << m_firstname;
	if (m_lastname.length() > 10)
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << m_lastname.substr(0, 9) + ".";
	else
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << m_lastname;
	if (m_nickname.length() > 10)
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << m_nickname.substr(0, 9) + "." << CYAN << "|\n" << RESET;
	else
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << m_nickname << CYAN << "|\n" << RESET;
	return (1);
}

// This function is used to obtained each variable input of the contacts object
void	Contacts::getInfoIndex(int index){
	std::cout << CYAN << "Index: " << RESET << index << std::endl;
	std::cout << CYAN << "First name: " << RESET << m_firstname << std::endl;
	std::cout << CYAN << "Last name: " << RESET << m_lastname << std::endl;
	std::cout << CYAN << "Nickname: " << RESET << m_nickname << std::endl;
	std::cout << CYAN << "Number: " << RESET << m_number << std::endl;
	std::cout << CYAN << "Darkest secret: " << RESET << m_secret << std::endl;
}

// This function is a getter function of the Contacts class to see if the current object contacts
// is not filled.
int	Contacts::getInfoIndexX(){
	if (m_firstname.empty())
		return (0);
	return (1);
}
