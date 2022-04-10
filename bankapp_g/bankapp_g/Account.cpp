#include <iostream>
#include <cstring>
#include "Account.h"

Account::Account()
	:accNum(0), balance(0), cusName(NULL)
{
}

Account::Account(const int& _accNum, const int& _balance, const char* _cusName)
	: accNum(_accNum), balance(_balance)
{
	cusName = new char[strlen(_cusName) + 1];
	strcpy_s(cusName, strlen(_cusName) + 1, _cusName);
}

int Account::GetAccNum() const
{
	return accNum;
}

int Account::GetBalance() const
{
	return balance;
}

char* Account::GetCusName() const
{
	return cusName;
}

void Account::Deposit(int _money)
{
	balance += _money;
}

void Account::Withdraw(int _money)
{
	balance -= _money;
}

void Account::ShowAccont() const
{
	std::cout << "°èÁÂ¹øÈ£: " << accNum << std::endl
		<< "ÀÌ ¸§: " << cusName << std::endl
		<< "ÀÜ ¾×: " << balance << std::endl;
}

Account::~Account()
{
	delete[]cusName;
}
