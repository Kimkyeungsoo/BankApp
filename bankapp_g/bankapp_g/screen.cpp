#include "screen.h"

#define CUSTOMER_LIST 100
/****************************************
* ���� ���� Ȯ��
****************************************/
int FineId(IdData* _str)
{
	int id = 0;
	std::cout << "���¹�ȣ: ";
	std::cin >> id;

	for (int i = 0; i < CUSTOMER_LIST; i++)
	{
		if (_str[i].ID == id)
		{
			return i;
		}
	}
	std::cout << "�ش� ���°� �����ϴ�." << std::endl;
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

		if (sellect == 1)
		{
			NewId(list, count);
		}
		else if (sellect == 2)
		{
			std::cout << "[�� ��]" << std::endl;

			int idnumber = FineId(list);
			if (idnumber >= 0)
			{
				Deposit(list, idnumber);
			}
		}
		else if (sellect == 3)
		{
			std::cout << "[�� ��]" << std::endl;

			int idnumber = FineId(list);
			if (idnumber >= 0)
			{
				Withdraw(list, idnumber);
			}
		}
		else if (sellect == 4)
		{
			std::cout << "# # # [��ü ���� ����] # # #" << std::endl << std::endl;

			IdDataShow(list, count);
		}
		else if (sellect == 5)
		{
			break;
		}

		std::cout << std::endl;
	}
}
/****************************************
* ���� ����
****************************************/
void NewId(IdData* _str, int& _count)
{
	int check = 0;
	if (_count == 0)
	{
		std::cout << "���¹�ȣ �Է�: ";
		std::cin >> _str[_count].ID;
	}
	else
	{
		std::cout << "���¹�ȣ �Է�: ";
		while (1)
		{
			int test = 0;
			std::cin >> _str[_count].ID;
			for (int i = 0; i < _count; i++)
			{
				if (_str[i].ID == _str[_count].ID)
				{
					test++;
					break;
				}
			}
			if (test == 0)
			{
				break;
			}
			else
			{
				check++;
				std::cout << "�ش� ���°� �����մϴ�." << std::endl;
				break;
			}
		}
	}
	if (check == 0)
	{
		std::cout << "�̸� �Է�: ";
		std::cin >> _str[_count].name;
		std::cout << "�Աݾ�: ";
		std::cin >> _str[_count].money;
	}
	_count++;
}
/****************************************
* �Ա�
****************************************/
void Deposit(IdData* _str, int _idnum)
{
	int _money = 0;
	std::cout << "�̸�: " << _str[_idnum].name << std::endl
		<< "�Աݾ�: ";
	while (1)
	{
		int choice = 1;
		std::cin >> _money;
		if (_money > 0)
		{
			_str[_idnum].money += _money;
			std::cout << "�Ա� �Ϸ�." << std::endl
				<< "�ܾ�: " << _str[_idnum].money << std::endl;
			break;
		}
		std::cout << "0������ �ݾ��Դϴ�. �ٽ� �Է� �Ͻðڽ��ϱ�?" << std::endl;

		while (choice != 1 && choice != 2)
		{
			std::cout << "1. �� 2. �ƴϿ�" << std::endl;
			std::cin >> choice;
		}
		if (choice == 1)
		{
			continue;
		}
		else if (choice == 2)
		{
			break;
		}
	}
}
/****************************************
* ���
****************************************/
void Withdraw(IdData* _str, int _idnum)
{
	int _money = 0;
	std::cout << "���� �ܾ�: " << _str[_idnum].money << std::endl
		<< "�̸�: " << _str[_idnum].name << std::endl
		<< "��ݾ�: ";
	while (1)
	{
		int choice = 1;
		std::cin >> _money;
		if (_money > 0)
		{
			if (_str[_idnum].money < _money)
			{
				std::cout << "��ݾ��� ���� �ܾ׺��� �����ϴ�." << std::endl;
				break;
			}
			else
			{
				_str[_idnum].money -= _money;
				std::cout << "��� �Ϸ�." << std::endl
					<< "�ܾ�: " << _str[_idnum].money << std::endl;
				break;
			}
		}
		std::cout << "0������ �ݾ��Դϴ�. �ٽ� �Է� �Ͻðڽ��ϱ�?" << std::endl;

		while (choice != 1 && choice != 2)
		{
			std::cout << "1. �� 2. �ƴϿ�" << std::endl;
			std::cin >> choice;
		}
		if (choice == 1)
		{
			continue;
		}
		else if (choice == 2)
		{
			break;
		}
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