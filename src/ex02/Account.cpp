//
// Created by fleanegan on 11.05.22.
//

#include <ctime>
#include "Account.hpp"

int Account::getNbAccounts(void) {
	return 0;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return 0;
}

int Account::getNbWithdrawals(void) {
	return 0;
}

void Account::displayAccountsInfos(void) {
_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits <<";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) :
_amount(initial_deposit),
_accountIndex(_nbAccounts++),
_nbDeposits(0),
_nbWithdrawals(0){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_totalAmount += initial_deposit;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	if (deposit > 0)
	{
		_amount += deposit;
		_totalAmount += deposit;
		++_nbDeposits;
		++_totalNbDeposits;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit<< ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits <<  std::endl;
	}
}

bool Account::makeWithdrawal(int withdrawal) {
	if (_amount - withdrawal >= 0)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals <<  std::endl;
		return (true);
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused"<<  std::endl;
	return false;
}

int Account::checkAmount(void) const {
	return 0;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount<< ";deposits:" << _nbDeposits<<";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	std::time_t t = std::time(nullptr);   // get time now
	std::tm* now = std::localtime(&t);
	std::cout
		<< "["
		<< (now->tm_year + 1900)
		<< (now->tm_mon + 1)
		<<  now->tm_mday
		<< "_"
		<< now->tm_hour
		<< now->tm_min
		<< now->tm_sec
		<< "] ";
}

Account::Account(void) {

}

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;