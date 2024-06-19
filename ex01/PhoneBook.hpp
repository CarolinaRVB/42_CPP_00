/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:07 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/19 14:39:24 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"
#include "iomanip"

class PhoneBook{
	private:
	Contacts	contacts[8] = {};

	public:
	int	oldest_index = 0;
	int	contact_index = -1;
	
	void	addInfo(const Contacts &contact);
	void	printContacts();
};


#endif