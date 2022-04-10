#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount()
	: addRate(0)
{
}

HighCreditAccount::HighCreditAccount(const int& _accNum, const int& _balance, const char* _cusName, const int& _addrate, const int& _rank)
	: NormalAccount(_accNum, _balance, _cusName, _addrate)
{
	switch (_addrate)
	{
	case RATIGN::A:
		addRate = 2;
		break;
	case RATIGN::B:
		addRate = 4;
		break;
	case RATIGN::C:
		addRate = 7;
		break;
	default:
		addRate = 0;
		break;
	}
}

int HighCreditAccount::GetAddRate()
{
	return addRate + GetRate();
}

void HighCreditAccount::Deposit(int _money)
{
	Account::Deposit(_money + (int)(GetBalance() * (GetAddRate() * 0.01)));
}
