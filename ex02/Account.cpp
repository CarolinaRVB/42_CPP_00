/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:07:25 by crebelo-          #+#    #+#             */
/*   Updated: 2024/06/22 14:36:37 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <stddef.h>   

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl; //dont put last line
}

int Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int Account::getTotalAmount( void ){
	return (_totalAmount);
}

int Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void	Account::_displayTimestamp(void){
	std::time_t	now = std::time(0);
	std::tm	*ltime = std::localtime(&now);

	std::cout << "[" << (1900 + ltime->tm_year) << (1 + ltime->tm_mon) << ltime->tm_mday << "_"
			<< (5 + ltime->tm_hour) << (30 + ltime->tm_min) << ltime->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void){
	_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit){
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount 
			  << ";deposit:" << deposit 
			  << ";amount:" << _amount + deposit 
			  <<";nb_deposits:" << _nbDeposits << std::endl;
	
	_amount += deposit;

}

bool	Account::makeWithdrawal(int withdrawal){
	
	_displayTimestamp();
	if (withdrawal > _amount){
		std::cout << "index:" << _accountIndex 
				  << ";p_amount:" << _amount 
				  << ";withdrawal:" << "refused"  << std::endl;
		return (false);
	}

	_totalNbWithdrawals++;
	_nbWithdrawals++;

	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount 
			  << ";withdrawal:" << withdrawal 
			  << ";amount:" << _amount - withdrawal 
			  <<";nb_withdrawals:" << _nbWithdrawals << std::endl;

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return(true);
}
