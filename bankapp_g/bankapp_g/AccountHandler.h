#pragma once

#include "Account.h"

class AccountHandler : public Account
{
private:
	Account* customer[100];
	int cusCount;
public:
	AccountHandler();
	void ShowMain();
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	int FindAccNum(const int _accNum);
	void ShowAllAccount();
	~AccountHandler();
};

