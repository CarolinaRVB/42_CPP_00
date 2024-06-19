/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:17 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/19 15:08:23 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// This functions checks if a string is composed of only spaces
int	checkIfOnlySpaces(std::string input){
	for (char ch : input){
		if (!std::isspace(ch))
			return (0) ;
	}
	return (1);
}

// This function checks if the inputs for the names are valid, meaning they can
// only be composed of alphabetical characters
int	checkNamesValidity(std::string input, std::string message){
	for (char ch : input){
		if (!std::isalpha(ch)){
			std::cout << RED << "WARNING: " << message << " can only contain alphabetical characters\n" << RESET;
			input.clear();
			return (1) ;
		}
	}
	return (0);
}

// This function is responsible for obtaining the inputs, parsing them and storing them in the object contacts
// of the class Contacts. It's the setter function for private information
void Contacts::infoSetter(){
	while (firstname.empty() || checkNamesValidity(firstname, "Firstname")){
		std::cout << "> " << BLUE << "Please enter first name: " << RESET;
		std::getline(std::cin, firstname);
	}
	while (lastname.empty() || checkNamesValidity(lastname, "Lastname")){
		std::cout  << "> " << BLUE << "Please enter last name: " << RESET;
		std::getline(std::cin, lastname);
	}
	while (nickname.empty() || checkNamesValidity(nickname, "Nickname")){
		std::cout << "> " << BLUE << "Please enter nickname: " << RESET;
		std::getline(std::cin, nickname);
	}
	while (secret.empty() ){
		std::cout << "> " << BLUE << "Please enter secret: " << RESET;
		std::getline(std::cin, secret);
		if (checkIfOnlySpaces(secret)){
			std::cout << RED << "WARNING: Secret can only contain alphanumerical characters\n" << RESET;
			secret.clear();
		}
	}
	while (number.empty()){
		std::cout << "> " << BLUE << "Please enter number: " << RESET;
		std::getline(std::cin, number);
		for (char ch : number)
			if (!std::isdigit(ch)){
				std::cout << RED << "WARNING: Number can only contain digits\n" << RESET;
				number.clear();
				break ;
			}
	}
}

// This function is used in the printContacts function and serves to check if each contacts variable has more
// than 10 characters, if so it prints the shortened version, otherwise it prints the original
int	Contacts::infoGetter(int index){
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
		std::cout << CYAN << "|" << RESET << std::right << std::setw(10) << nickname << CYAN << "|\n" << RESET;
	return (1);
}

// This function is used to obtained each variable input of the contacts object
void	Contacts::infoIndexGetter(int index){
	std::cout << CYAN << "Index: " << RESET << index << std::endl;
	std::cout << CYAN << "First name: " << RESET << firstname << std::endl;
	std::cout << CYAN << "Last name: " << RESET << lastname << std::endl;
	std::cout << CYAN << "Nickname: " << RESET << nickname << std::endl;
	std::cout << CYAN << "Number: " << RESET << number << std::endl;
	std::cout << CYAN << "Darkest secret: " << RESET << secret << std::endl;
}

// This function is a getter function of the Contacts class to see if the current object contacts
// is not filled.
int	Contacts::infoIndexXChecker(){
	if (firstname.empty())
		return (0);
	return (1);
}
