#include "AccountHandler.h"

#include <iostream>

AccountHandler::AccountHandler()
	: cusCount(0)
{
	for (int i = 0; i < 100; i++)
	{
		customer[i] = 0;
	}
}

void AccountHandler::ShowMain()
{
	std::cout
		<< "┌────────── [ Menu ]───────────┐" << std::endl
		<< "│     1. 계좌개설              │" << std::endl
		<< "│     2. 입 금                 │" << std::endl
		<< "│     3. 출 금                 │" << std::endl
		<< "│     4. 계좌정보 전체 출력    │" << std::endl
		<< "│     5. 프로그램 종료         │" << std::endl
		<< "└──────────────────────────────┘" << std::endl;
}

void AccountHandler::MakeAccount()
{
	std::cout << "========== 계좌 개설 ===========" << std::endl;
	int id = 0;
	int money = 0;
	char name[30] = { 0 };
	std::cout << "계좌번호: ";
	std::cin >> id;
	if (id <= 0)
	{
		std::cout << "잘못된 입력입니다." << std::endl;
	}
	else if (FindAccNum(id) == -1)
	{
		std::cout << "이 름: ";
		std::cin >> name;
		std::cout << "입금액: ";
		std::cin >> money;
		if (money <= 0)
		{
			std::cout << "잘못된 입력입니다." << std::endl;
		}
		else
		{
			customer[cusCount] = new Account(id, money, name);
			cusCount++;
		}
	}
	else
	{
		std::cout << "해당 계좌번호가 이미 존재합니다." << std::endl;
	}
	std::cout << "================================" << std::endl;
}

void AccountHandler::DepositMoney()
{
	std::cout << "============ 입 금 =============" << std::endl;
	int id = 0;
	int money = 0;

	std::cout << "계좌번호: ";
	std::cin >> id;
	int i = FindAccNum(id);
	if (i != -1)
	{
		std::cout << "이 름: " << customer[i]->GetCusName() << std::endl;
		std::cout << "입금액: ";
		std::cin >> money;

		if (money > 0)
		{
			customer[i]->Deposit(money);
			std::cout << "입금 완료" << std::endl
				<< "잔 액: " << customer[i]->GetBalance() << std::endl;
		}
		else
		{
			std::cout << "잘못된 입력입니다." << std::endl;
		}
	}
	else
	{
		std::cout << "해당 계좌를 찾을 수 없습니다." << std::endl;
	}
	std::cout << "================================" << std::endl;
}

void AccountHandler::WithdrawMoney()
{
	std::cout << "============ 출 금 =============" << std::endl;
	int id = 0;
	int money = 0;

	std::cout << "계좌번호: ";
	std::cin >> id;
	int i = FindAccNum(id);
	if (i != -1)
	{
		std::cout << "이 름: " << customer[i]->GetCusName() << std::endl;
		std::cout << "출금액: ";
		std::cin >> money;
		if (money > customer[i]->GetBalance())
		{
			std::cout << "잔액이 부족합니다.." << std::endl;
		}
		else if (money > 0)
		{
			customer[i]->Withdraw(money);
			std::cout << "출금 완료" << std::endl
				<< "잔 액: " << customer[i]->GetBalance() << std::endl;
		}
		else
		{
			std::cout << "잘못된 입력입니다." << std::endl;
		}
	}
	else
	{
		std::cout << "해당 계좌를 찾을 수 없습니다." << std::endl;
	}
	std::cout << "================================" << std::endl;
}

int AccountHandler::FindAccNum(const int _accNum)
{
	for (int i = 0; i < cusCount; i++)
	{
		if (customer[i]->GetAccNum() == _accNum)
		{
			return i;
		}
	}
	return -1;
}

void AccountHandler::ShowAllAccount()
{
	std::cout << "===== 계좌 정보 전체 출력 ======" << std::endl;
	for (int i = 0; i < cusCount; i++)
	{
		customer[i]->ShowAccont();
		std::cout << std::endl;
	}
	std::cout << "================================" << std::endl;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < cusCount; i++)
	{
		customer[i]->~Account();
	}
}
