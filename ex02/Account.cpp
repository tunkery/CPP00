/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:27:39 by bolcay            #+#    #+#             */
/*   Updated: 2025/10/28 14:29:04 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	main()
{
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void    Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

}

bool    Account::makeWithdrawal(int withdrawal)
{
	// here comes an if condition
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
    return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void    Account::displayStatus(void) const
{
}

void Account::_displayTimestamp(void)
{
	time_t	ctime;
	tm		*utime;

	ctime = time(nullptr);
	utime = gmtime(&ctime);
	std::cout << "[" << 1900 + utime->tm_year << 1 + utime->tm_mon << utime->tm_mday << "_"
			  << utime->tm_hour << utime->tm_min << utime->tm_sec << "]" << " " << std::endl;
}
