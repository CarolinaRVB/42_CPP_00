/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:28:28 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/10 16:36:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	if (!argv[1]){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; argv[i]; i++){
		for (int j = 0; argv[i][j]; j++){
			if (std::islower(argv[i][j]))
				std::cout << (char)std::toupper(argv[i][j]);
			else
				std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;

	return (0);
}