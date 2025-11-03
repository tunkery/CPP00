/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:27:39 by bolcay            #+#    #+#             */
/*   Updated: 2025/11/03 10:13:13 by bolcay           ###   ########.fr       */
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
	bool	status;

	status = false;
	if (_amount >= withdrawal)
	{
		status = true;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
	}
	displayStatus();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (status)
		std::cout << ";withdrawal:" << withdrawal << ";amount:"
				  << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	else
		std::cout << ";withdrawal:refused";
    return (status);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits << ";withdrawals:"
			  << _totalNbWithdrawals << std::endl;
}

void    Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits << ";withdrawals:"
			  << _nbWithdrawals << std::endl;
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
