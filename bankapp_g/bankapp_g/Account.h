#pragma once

// 구조체 배열로 만들어야합니다.
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