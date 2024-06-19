/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:07 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/19 16:06:25 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"
#include "iomanip"
#include <iostream>

class PhoneBook{
	private:
		Contacts	contacts[8];

	public:	
		PhoneBook();
		~PhoneBook();
	
		int	oldest_index;
		int	contact_index;
		
		void	addInfo(const Contacts &contact);
		void	printContacts();
};


#endif