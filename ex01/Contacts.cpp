/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:17 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/18 20:28:46 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	checkIfOnlySpaces(std::string input){
	for (char ch : input){
		if (!std::isspace(ch))
			return (0) ;
	}
	return (1);
}

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

void	Contacts::infoIndexGetter(int index){
	std::cout << CYAN << "Index: " << RESET << index << std::endl;
	std::cout << CYAN << "First name: " << RESET << firstname << std::endl;
	std::cout << CYAN << "Last name: " << RESET << lastname << std::endl;
	std::cout << CYAN << "Nickname: " << RESET << nickname << std::endl;
	std::cout << CYAN << "Number: " << RESET << number << std::endl;
	std::cout << CYAN << "Darkest secret: " << RESET << secret << std::endl;
}

int	Contacts::infoIndexXChecker(){
	if (firstname.empty())
		return (0);
	return (1);
}
