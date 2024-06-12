/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:52:07 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/12 08:59:58 by crebelo-         ###   ########.fr       */
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
	int	oldest = 0;
	int	index[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int	ncontact = 0;
	int	empty = 1;
	
	void	add_info(const Contacts &contact, PhoneBook &phonebook);
	void	print_contacts(const PhoneBook &phonebook);
	void	get_next_index(PhoneBook &phonebook);
};


#endif