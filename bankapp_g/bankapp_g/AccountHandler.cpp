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
		<< "���������������������� [ Menu ]������������������������" << std::endl
		<< "��     1. ���°���              ��" << std::endl
		<< "��     2. �� ��                 ��" << std::endl
		<< "��     3. �� ��                 ��" << std::endl
		<< "��     4. �������� ��ü ���    ��" << std::endl
		<< "��     5. ���α׷� ����         ��" << std::endl
		<< "����������������������������������������������������������������" << std::endl;
}

void AccountHandler::MakeAccount()
{
	std::cout << "========== ���� ���� ===========" << std::endl;
	int id = 0;
	int money = 0;
	char name[30] = { 0 };
	std::cout << "���¹�ȣ: ";
	std::cin >> id;
	if (id <= 0)
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
	else if (FindAccNum(id) == -1)
	{
		std::cout << "�� ��: ";
		std::cin >> name;
		std::cout << "�Աݾ�: ";
		std::cin >> money;
		if (money <= 0)
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else
		{
			customer[cusCount] = new Account(id, money, name);
			cusCount++;
		}
	}
	else
	{
		std::cout << "�ش� ���¹�ȣ�� �̹� �����մϴ�." << std::endl;
	}
	std::cout << "================================" << std::endl;
}

void AccountHandler::DepositMoney()
{
	std::cout << "============ �� �� =============" << std::endl;
	int id = 0;
	int money = 0;

	std::cout << "���¹�ȣ: ";
	std::cin >> id;
	int i = FindAccNum(id);
	if (i != -1)
	{
		std::cout << "�� ��: " << customer[i]->GetCusName() << std::endl;
		std::cout << "�Աݾ�: ";
		std::cin >> money;

		if (money > 0)
		{
			customer[i]->Deposit(money);
			std::cout << "�Ա� �Ϸ�" << std::endl
				<< "�� ��: " << customer[i]->GetBalance() << std::endl;
		}
		else
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
	}
	else
	{
		std::cout << "�ش� ���¸� ã�� �� �����ϴ�." << std::endl;
	}
	std::cout << "================================" << std::endl;
}

void AccountHandler::WithdrawMoney()
{
	std::cout << "============ �� �� =============" << std::endl;
	int id = 0;
	int money = 0;

	std::cout << "���¹�ȣ: ";
	std::cin >> id;
	int i = FindAccNum(id);
	if (i != -1)
	{
		std::cout << "�� ��: " << customer[i]->GetCusName() << std::endl;
		std::cout << "��ݾ�: ";
		std::cin >> money;
		if (money > customer[i]->GetBalance())
		{
			std::cout << "�ܾ��� �����մϴ�.." << std::endl;
		}
		else if (money > 0)
		{
			customer[i]->Withdraw(money);
			std::cout << "��� �Ϸ�" << std::endl
				<< "�� ��: " << customer[i]->GetBalance() << std::endl;
		}
		else
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
	}
	else
	{
		std::cout << "�ش� ���¸� ã�� �� �����ϴ�." << std::endl;
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
	std::cout << "===== ���� ���� ��ü ��� ======" << std::endl;
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
