#pragma once

#include "Account.h"

class NormalAccount : public Account
{
private:
	int basicRate;
public:
	NormalAccount();
	NormalAccount(const int& _accNum, const int& _balance, const char* _cusName, const int& _basicrate);
	int GetRate();
	void SetRate(const int _num);
	virtual void Deposit(int _money);
};

