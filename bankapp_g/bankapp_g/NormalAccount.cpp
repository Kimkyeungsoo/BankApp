#include "NormalAccount.h"

NormalAccount::NormalAccount()
	: basicRate(0)
{
}

NormalAccount::NormalAccount(const int& _accNum, const int& _balance, const char* _cusName, const int& _basicrate)
	: Account(_accNum, _balance, _cusName), basicRate(_basicrate)
{
}

int NormalAccount::GetRate()
{
	return basicRate;
}

void NormalAccount::SetRate(const int _num)
{
	basicRate = _num;
}

void NormalAccount::Deposit(int _money)
{
	Account::Deposit(_money + (int)(GetBalance() * GetRate() * 0.01));
}
