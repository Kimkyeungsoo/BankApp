#pragma once

// ����ü �迭�� �������մϴ�.
class Account
{
private:
	int accNum;
	int balance;
	char* cusName;
public:
	Account();
	Account(const int& _accNum, const int& _balance, const char* _cusName);
	int GetAccNum();
	int GetBalance();
	char* GetCusName();
	void Deposit(int _money);
	void Withdraw(int _money);
	void ShowAccont() const;
	~Account();
};