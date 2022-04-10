#pragma once

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int addRate;
public:
	HighCreditAccount();
	HighCreditAccount(const int& _accNum, const int& _balance, const char* _cusName, const int& _basicrate, const int& _rank);
	int GetAddRate();
	virtual void Deposit(int _money);
};

enum RATIGN
{
	A = 1,
	B = 2,
	C = 3
};
