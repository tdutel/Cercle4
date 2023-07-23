/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:31:28 by tdutel            #+#    #+#             */
/*   Updated: 2023/07/18 18:04:19 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Variables Initialisation //

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor and Destructor //

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_nbAccounts++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	this->_amount += initial_deposit;
	this->_totalAmount += this->_amount;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	this->_totalAmount += this->_amount;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

// Get Attribut //

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

// Display Functions //

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp()
{
	std::time_t now = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&now);

    int heure = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;
    int seconde = timeInfo->tm_sec;
    int jour = timeInfo->tm_mday;
    int mois = timeInfo->tm_mon + 1;
    int annee = timeInfo->tm_year + 1900;

    std::cout << "[" << annee
	<< std::setfill('0') << std::setw(2) << mois
	<< std::setfill('0') << std::setw(2) << jour << "_"
	<< std::setfill('0') << std::setw(2) << heure
	<< std::setfill('0') << std::setw(2) << minute
	<< std::setfill('0') << std::setw(2) << seconde << "] ";
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" ;
	std::cout << "amount:" << this->_amount << ";" ;
	std::cout << "deposits:" << this->_nbDeposits << ";" ;
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Make Functions //

void	Account::makeDeposit( int deposit )
{
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits +=1 ;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (checkAmount() - withdrawal >= 0)
	{
		this->_nbWithdrawals += 1;
		this->_totalNbWithdrawals += 1;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		std::cout << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	else
		std::cout << "refused" << std::endl;
	return false;
}

// Check Function //

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

