/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:54:59 by pgros             #+#    #+#             */
/*   Updated: 2023/03/21 13:28:43 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

//constructors and destructors
// Account::Account()
// {
// 	//std::cout << "Default constructor of Account called." << std::endl;
// }
// Account::Account(const Account& other)
// {
// (void)other;
// 	//std::cout << "Copy constructor of Account called." << std::endl;
// }

void	Account::_displayTimestamp( void )
{
	time_t	t = time(NULL);
	struct tm *tm = localtime(&t);
	 
	std::cout << "[" << 1900 + tm->tm_year << "] ";
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";" ;
	std::cout << "created" << std::endl ;
}
Account::~Account()
{
	//std::cout << "Destructor of Account called." << std::endl;
}
//overloads
// Account& Account::operator=(const Account& rhs)
// {
// (void)rhs;
// 	return *this;
// }