#include "screen.h"

#define CUSTOMER_LIST 100
/****************************************
* 계좌 존재 확인
****************************************/
int FineId(IdData* _str)
{
	int id = 0;
	std::cout << "계좌번호: ";
	std::cin >> id;

	for (int i = 0; i < CUSTOMER_LIST; i++)
	{
		if (_str[i].ID == id)
		{
			return i;
		}
	}
	std::cout << "해당 계좌가 없습니다." << std::endl;
	return -1;
}
/****************************************
* 동작
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
				<< "┌────────── [ Menu ]───────────┐" << std::endl
				<< "│     1. 계좌개설              │" << std::endl
				<< "│     2. 입 금                 │" << std::endl
				<< "│     3. 출 금                 │" << std::endl
				<< "│     4. 계좌정보 전체 출력    │" << std::endl
				<< "│     5. 프로그램 종료         │" << std::endl
				<< "└──────────────────────────────┘" << std::endl
				<< "선택: ";
			std::cin >> sellect;
			if (sellect >= 1 && sellect <= 5)
			{
				break;
			}
			else
			{
				std::cout << "잘못된 선택입니다. 다시 선택하세요" << std::endl << std::endl;
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
			std::cout << "[입 금]" << std::endl;

			int idnumber = FineId(list);
			if (idnumber >= 0)
			{
				Deposit(list, idnumber);
			}
		}
		else if (sellect == 3)
		{
			std::cout << "[출 금]" << std::endl;

			int idnumber = FineId(list);
			if (idnumber >= 0)
			{
				Withdraw(list, idnumber);
			}
		}
		else if (sellect == 4)
		{
			std::cout << "# # # [전체 계좌 정보] # # #" << std::endl << std::endl;

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
* 계좌 개설
****************************************/
void NewId(IdData* _str, int& _count)
{
	int check = 0;
	if (_count == 0)
	{
		std::cout << "계좌번호 입력: ";
		std::cin >> _str[_count].ID;
	}
	else
	{
		std::cout << "계좌번호 입력: ";
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
				std::cout << "해당 계좌가 존재합니다." << std::endl;
				break;
			}
		}
	}
	if (check == 0)
	{
		std::cout << "이름 입력: ";
		std::cin >> _str[_count].name;
		std::cout << "입금액: ";
		std::cin >> _str[_count].money;
	}
	_count++;
}
/****************************************
* 입금
****************************************/
void Deposit(IdData* _str, int _idnum)
{
	int _money = 0;
	std::cout << "이름: " << _str[_idnum].name << std::endl
		<< "입금액: ";
	while (1)
	{
		int choice = 1;
		std::cin >> _money;
		if (_money > 0)
		{
			_str[_idnum].money += _money;
			std::cout << "입금 완료." << std::endl
				<< "잔액: " << _str[_idnum].money << std::endl;
			break;
		}
		std::cout << "0이하의 금액입니다. 다시 입력 하시겠습니까?" << std::endl;

		while (choice != 1 && choice != 2)
		{
			std::cout << "1. 예 2. 아니요" << std::endl;
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
* 출금
****************************************/
void Withdraw(IdData* _str, int _idnum)
{
	int _money = 0;
	std::cout << "현재 잔액: " << _str[_idnum].money << std::endl
		<< "이름: " << _str[_idnum].name << std::endl
		<< "출금액: ";
	while (1)
	{
		int choice = 1;
		std::cin >> _money;
		if (_money > 0)
		{
			if (_str[_idnum].money < _money)
			{
				std::cout << "출금액이 현재 잔액보다 많습니다." << std::endl;
				break;
			}
			else
			{
				_str[_idnum].money -= _money;
				std::cout << "출금 완료." << std::endl
					<< "잔액: " << _str[_idnum].money << std::endl;
				break;
			}
		}
		std::cout << "0이하의 금액입니다. 다시 입력 하시겠습니까?" << std::endl;

		while (choice != 1 && choice != 2)
		{
			std::cout << "1. 예 2. 아니요" << std::endl;
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
* 전체 계좌정보 출력
****************************************/
void IdDataShow(IdData* _str, int _idnum)
{
	for (int i = 0; i < _idnum; i++)
	{
		std::cout << "계좌번호: " << _str[i].ID << std::endl
			<< "이 름: " << _str[i].name << std::endl
			<< "잔 액: " << _str[i].money << std::endl
			<< std::endl;
	}
}