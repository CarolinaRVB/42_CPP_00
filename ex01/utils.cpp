/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:01 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/19 16:13:43 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

// This functions checks if a string is composed of only spaces
int	checkIfOnlySpaces(std::string input){
	for (int i = 0; input[i]; i++){
		if (!std::isspace(input[i]))
			return (0) ;
	}
	return (1);
}

// This function checks if the inputs for the names are valid, meaning they can
// only be composed of alphabetical characters
int	checkNamesValidity(std::string input, std::string message){
	for (int i = 0; input[i]; i++){
		if (!std::isalpha(input[i])){
			std::cout << RED << "WARNING: " << message << " can only contain alphabetical characters\n" << RESET;
			input.clear();
			return (1) ;
		}
	}
	return (0);
}

// This function is a custom function to convert a string to an integer
// since the function stoi is not allowed for c++98
int customStoi(std::string input){
    int result;
    
    std::istringstream iss (input);
    iss >> result;
    return (result);
}
