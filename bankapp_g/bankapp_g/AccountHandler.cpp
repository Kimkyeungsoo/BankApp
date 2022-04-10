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

void AccountHandler::ShowMain() const
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

void AccountHandler::AccountType()
{
	int sellect = 0;
	std::cout
		<< "������������ [ �������� ���� ]����������������" << std::endl
		<< "��     1. ���뿹�ݰ���          ��" << std::endl
		<< "��     2. �ſ�ŷڰ���          ��" << std::endl
		<< "����������������������������������������������������������������" << std::endl;
	std::cout << "����: ";
	std::cin >> sellect;

	switch (sellect)
	{
	case 1:
		MakeNormal();
		break;
	case 2:
		MakeHighCredit();
		break;
	default:
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		break;
	}
}

void AccountHandler::MakeNormal()
{
	std::cout << "======== ���뿹�ݰ��� ==========" << std::endl;
	int id = 0;
	int money = 0;
	int rate = 0;
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
		std::cout << "������: ";
		std::cin >> rate;
		if (money < 0 || rate < 0)
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else
		{
			customer[cusCount] = new NormalAccount(id, money, name, rate);
			cusCount++;
		}
	}
	else
	{
		std::cout << "�ش� ���¹�ȣ�� �̹� �����մϴ�." << std::endl;
	}
	std::cout << "================================" << std::endl;
}

void AccountHandler::MakeHighCredit()
{
	std::cout << "======== �ſ�ŷڰ��� ==========" << std::endl;
	int id = 0;
	int money = 0;
	int rate = 0;
	int rank = 0;
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
		std::cout << "������: ";
		std::cin >> rate;
		std::cout << "�ſ���(1toA: 7%, 2toB 4%, 3toC 2%): ";
		std::cin >> rank;
		if (money < 0 || rate < 0 || (rank < 1 || rank > 3))
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else
		{
			customer[cusCount] = new HighCreditAccount(id, money, name, rate, rank);
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
