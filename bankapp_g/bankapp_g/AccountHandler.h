#pragma once

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

class AccountHandler
{
private:
	Account* customer[100];
	int cusCount;
public:
	AccountHandler();

	void ShowMain() const;
	void AccountType();
	void MakeNormal();
	void MakeHighCredit();
	void DepositMoney();
	void WithdrawMoney();
	int FindAccNum(const int _accNum);
	void ShowAllAccount();

	~AccountHandler();
};

enum Sellect
{
	MAKE = 1,
	DEPOS = 2,
	WITHDRAW = 3,
	SHOW = 4,
	EXIT = 5
};


