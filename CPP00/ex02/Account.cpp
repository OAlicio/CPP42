/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:20:43 by ofeverei          #+#    #+#             */
/*   Updated: 2026/02/17 16:51:32 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	std::cout << "index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";created"
		<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";closed"
		<< std::endl;
}

void	Account::_displayTimestamp()
{
	time_t	times;
	struct tm timestamp;

	time(&times);
	timestamp = *localtime(&times);
	std::cout << "["
		<< timestamp.tm_year + 1900
		<< std::setw(2) << std::setfill('0') << timestamp.tm_mon + 1
		<< std::setw(2) << std::setfill('0') << timestamp.tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << timestamp.tm_hour
		<< std::setw(2) << std::setfill('0') << timestamp.tm_min
		<< std::setw(2) << std::setfill('0') << timestamp.tm_sec
		<< "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (deposit > 0)
	{
		Account::_totalNbDeposits++;
		this->_nbDeposits++;
		Account::_totalAmount += deposit;
		this->_amount += deposit;
		std::cout << ";deposit:"
			<< deposit
			<< ";amount:"
			<< this->_amount
			<< ";nb_deposits:"
			<< this->_nbDeposits
			<< std::endl;
	}
	else
		std::cout << ";deposit:refused" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if ((this->_amount - withdrawal) >= 0)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << ";withdraw:"
			<< withdrawal
			<< ";amount:"
			<< this->_amount
			<< ";nb_withdrawals:"
			<< this->_nbWithdrawals
			<< std::endl;
		return (true);
	}
	std::cout << ";withdrawal:refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";deposits:"
		<< this->_nbDeposits
		<< ";withdrawals:"
		<< this->_nbWithdrawals
		<< std::endl;
}

int	Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:"
		<< Account::getNbAccounts()
		<< ";total:"
		<< Account::getTotalAmount()
		<< ";deposits:"
		<< Account::getNbDeposits()
		<< ";withdrawals:"
		<< Account::getNbWithdrawals()
		<< std::endl;
}
