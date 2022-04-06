#include "screen.h"

// ���� �ؾ� �� ����
// 1. ���ʿ��� �ݺ��� ����
// 2. NewId ������ FineId�� ����Ͽ� ����

#define CUSTOMER_LIST 100
/****************************************
* ���� ���� Ȯ��
****************************************/
int FineId(IdData* _str, int _id, const int _count)
{
	for (int i = 0; i < _count; i++)
	{
		if (_str[i].ID == _id)
		{
			return i;
		}
	}
	return -1;
}
/****************************************
* ����
****************************************/
void MainScreen()
{
	IdData list[CUSTOMER_LIST] = { 0, };
	int count = 0;
	while (1)
	{
		int id = 0;
		int sellect = 0;
		while (1)
		{
			std::cout
				<< "���������������������� [ Menu ]������������������������" << std::endl
				<< "��     1. ���°���              ��" << std::endl
				<< "��     2. �� ��                 ��" << std::endl
				<< "��     3. �� ��                 ��" << std::endl
				<< "��     4. �������� ��ü ���    ��" << std::endl
				<< "��     5. ���α׷� ����         ��" << std::endl
				<< "����������������������������������������������������������������" << std::endl
				<< "����: ";
			std::cin >> sellect;
			if (sellect >= 1 && sellect <= 5)
			{
				break;
			}
			else
			{
				std::cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���" << std::endl << std::endl;
				continue;
			}
		}
		std::cout << std::endl;

		switch (sellect)
		{
		case 1:
			std::cout << "# # # [���� ����] # # #" << std::endl << std::endl;
			NewId(list, count);
			break;
		case 2:
			std::cout << "[�� ��]" << std::endl;
			Deposit(list, count);
			break;
		case 3:
			std::cout << "[�� ��]" << std::endl;
			Withdraw(list, count);
			break;
		case 4:
			std::cout << "# # # [��ü ���� ����] # # #" << std::endl << std::endl;
			IdDataShow(list, count);
			break;
		}

		if (sellect == 5)
		{
			break;
		}

		std::cout << std::endl;
	}
}
/****************************************
* ���� ����
****************************************/
void NewId(IdData* _list, int& _count)
{
	std::cout << "���¹�ȣ: ";
	std::cin >> _list[_count].ID;
	if (_count == 0 || FineId(_list, _list[_count].ID, _count) == -1)
	{
		std::cout << "�� ��: ";
		std::cin >> _list[_count].name;
		std::cout << "�Աݾ�: ";
		std::cin >> _list[_count].money;
		_count++;
	}
	else
	{
		_list[_count].ID = 0;
		std::cout << "�ش� ���°� ���� �մϴ�." << std::endl;
	}
}
/****************************************
* �Ա�
****************************************/
void Deposit(IdData* _list, const int _count)
{
	int id = 0;
	std::cout << "���¹�ȣ: ";
	std::cin >> id;
	int i = FineId(_list, id, _count);
	if (i != -1)
	{
		int money = 0;
		std::cout << "�� ��: " << _list[i].name << std::endl
			<< "�ܾ�: " << _list[i].money << std::endl
			<< "�Աݾ�: ";
		std::cin >> money;
		if (money > 0)
		{
			_list[i].money += money;
			std::cout << "�Ա� �Ϸ�" << std::endl;
		}
		else
		{
			std::cout << "�Է� �ݾ��� 0���� �۽��ϴ�." << std::endl;
		}
	}
	else
	{
		std::cout << "�ش� ���°� �����ϴ�." << std::endl;
	}
}
/****************************************
* ���
****************************************/
void Withdraw(IdData* _list, const int _count)
{
	int id = 0;
	std::cout << "���¹�ȣ: ";
	std::cin >> id;
	int i = FineId(_list, id, _count);
	if (i != -1)
	{
		int money = 0;
		std::cout << "�� ��: " << _list[i].name << std::endl
			<< "�ܾ�: " << _list[i].money << std::endl
			<< "��ݾ�: ";
		std::cin >> money;
		if (money > 0 && money <= _list[i].money)
		{
			_list[i].money += money;
			std::cout << "��� �Ϸ�" << std::endl;
		}
		else
		{
			std::cout << "�Է� �ݾ��� 0���� �۰ų� �ܾ׺��� Ů�ϴ�." << std::endl;
		}
	}
	else
	{
		std::cout << "�ش� ���°� �����ϴ�." << std::endl;
	}
}
/****************************************
* ��ü �������� ���
****************************************/
void IdDataShow(IdData* _str, int _idnum)
{
	for (int i = 0; i < _idnum; i++)
	{
		std::cout << "���¹�ȣ: " << _str[i].ID << std::endl
			<< "�� ��: " << _str[i].name << std::endl
			<< "�� ��: " << _str[i].money << std::endl
			<< std::endl;
	}
}