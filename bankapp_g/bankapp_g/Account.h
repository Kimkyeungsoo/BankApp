#pragma once

class Account
{
private:
	int accNum;
	int balance;
	char* cusName;
public:
	Account();
	Account(const int& _accNum, const int& _balance, const char* _cusName);
	int GetAccNum() const;
	int GetBalance() const;
	char* GetCusName() const;
	virtual void Deposit(int _money);
	void Withdraw(int _money);
	void ShowAccont() const;
	~Account();
};