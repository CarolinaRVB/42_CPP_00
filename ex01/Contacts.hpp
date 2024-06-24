/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:41 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/19 16:12:37 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <sstream>

// ANSI escape codes for colors
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";

class Contacts{
	
	private:
		std::string	m_number;
		std::string m_firstname;
		std::string m_lastname;
		std::string m_nickname;
		std::string m_secret;
	
	public:
		void	setInfo();
		int		getInfo(int index);
		void	getInfoIndex(int index);
		int 	getInfoIndexX();
};

int	checkIfOnlySpaces(std::string input);
int	checkNamesValidity(std::string input, std::string message);
int customStoi(std::string input);

#endif