#include "Account.hpp"
#include <iostream>
#include <iomanip>

/**
 * @brief No, I did not wrote these with any particular intention other than blind: NO CODE DUPLICATE
 * Only takeaway is probably defining a macro to avoid typo
 */

#define DEPOSIT		"deposit"
#define WITHDRAWAL	"withdrawal"
#define INDEX		"index"
#define AMOUNT		"amount"
#define CLOSED		"closed"
#define CREATED		"created"
#define COLON		":"
#define SEMICOLON	";"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	put(std::string name, int nbr, std::string append)
{
	std::cout << name << COLON << nbr << append;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	put(INDEX, _accountIndex, SEMICOLON);
	put(AMOUNT, _amount, SEMICOLON);
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	put(INDEX, _accountIndex, SEMICOLON);
	put(AMOUNT, _amount, SEMICOLON);
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	put("accounts", _nbAccounts, SEMICOLON);
	put("total", _totalAmount, SEMICOLON);
	put(DEPOSIT"s", _totalNbDeposits, SEMICOLON);
	put(WITHDRAWAL"s", _totalNbWithdrawals, "\n");
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	put(INDEX, _accountIndex, SEMICOLON);
	put("p_amount", _amount, SEMICOLON);
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	put(DEPOSIT, deposit, SEMICOLON);
	put(AMOUNT, _amount, SEMICOLON);
	put("nb_deposits", ++_nbDeposits, "\n");
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	put(INDEX, _accountIndex, SEMICOLON);
	put("p_amount", _amount, SEMICOLON);
	if (withdrawal > _amount)
	{
		std::cout << WITHDRAWAL << COLON << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	put(WITHDRAWAL, withdrawal, SEMICOLON);
	put(AMOUNT, _amount, SEMICOLON);
	put("nb_withdrawals", ++_nbWithdrawals, "\n");
	return (true);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	put(INDEX, _accountIndex, SEMICOLON);
	put(AMOUNT, _amount, SEMICOLON);
	put(DEPOSIT"s", _nbDeposits, SEMICOLON);
	put(WITHDRAWAL"s", _nbWithdrawals, "\n");
}

void	Account::_displayTimestamp(void)
{
	time_t	raw = time(NULL);
	tm		*now = localtime(&raw);

	std::cout << std::setfill('0')
		<< "["
		<< now->tm_year + 1900
		<< std::setw(2) << now->tm_mon + 1
		<< std::setw(2) << now->tm_mday
		<< '_'
		<< std::setw(2) << now->tm_hour
		<< std::setw(2) << now->tm_min
		<< std::setw(2) << now->tm_sec
		<< "]" << " " << std::setfill(' ');
	// std::cout << "[19920104_091532] "; (void)now;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}
