#include "screen.h"

// 수정 해야 할 사항
// 1. 불필요한 반복문 제거
// 2. NewId 에서도 FineId를 사용하여 변경

#define CUSTOMER_LIST 100
/****************************************
* 계좌 존재 확인
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

		switch (sellect)
		{
		case 1:
			std::cout << "# # # [계좌 개설] # # #" << std::endl << std::endl;
			NewId(list, count);
			break;
		case 2:
			std::cout << "[입 금]" << std::endl;
			Deposit(list, count);
			break;
		case 3:
			std::cout << "[출 금]" << std::endl;
			Withdraw(list, count);
			break;
		case 4:
			std::cout << "# # # [전체 계좌 정보] # # #" << std::endl << std::endl;
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
* 계좌 개설
****************************************/
void NewId(IdData* _list, int& _count)
{
	std::cout << "계좌번호: ";
	std::cin >> _list[_count].ID;
	if (_count == 0 || FineId(_list, _list[_count].ID, _count) == -1)
	{
		std::cout << "이 름: ";
		std::cin >> _list[_count].name;
		std::cout << "입금액: ";
		std::cin >> _list[_count].money;
		_count++;
	}
	else
	{
		_list[_count].ID = 0;
		std::cout << "해당 계좌가 존재 합니다." << std::endl;
	}
}
/****************************************
* 입금
****************************************/
void Deposit(IdData* _list, const int _count)
{
	int id = 0;
	std::cout << "계좌번호: ";
	std::cin >> id;
	int i = FineId(_list, id, _count);
	if (i != -1)
	{
		int money = 0;
		std::cout << "이 름: " << _list[i].name << std::endl
			<< "잔액: " << _list[i].money << std::endl
			<< "입금액: ";
		std::cin >> money;
		if (money > 0)
		{
			_list[i].money += money;
			std::cout << "입금 완료" << std::endl;
		}
		else
		{
			std::cout << "입력 금액이 0보다 작습니다." << std::endl;
		}
	}
	else
	{
		std::cout << "해당 계좌가 없습니다." << std::endl;
	}
}
/****************************************
* 출금
****************************************/
void Withdraw(IdData* _list, const int _count)
{
	int id = 0;
	std::cout << "계좌번호: ";
	std::cin >> id;
	int i = FineId(_list, id, _count);
	if (i != -1)
	{
		int money = 0;
		std::cout << "이 름: " << _list[i].name << std::endl
			<< "잔액: " << _list[i].money << std::endl
			<< "출금액: ";
		std::cin >> money;
		if (money > 0 && money <= _list[i].money)
		{
			_list[i].money += money;
			std::cout << "출금 완료" << std::endl;
		}
		else
		{
			std::cout << "입력 금액이 0보다 작거나 잔액보다 큽니다." << std::endl;
		}
	}
	else
	{
		std::cout << "해당 계좌가 없습니다." << std::endl;
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