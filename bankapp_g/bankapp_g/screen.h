#pragma once

#include <iostream>

// ����ü �迭�� �������մϴ�.
typedef struct IdData
{
	int ID;
	int money;
	char name[20];
} IdData;
/// <summary>
/// ���� �˻��ϴ� �Լ�
/// </summary>
/// <param name="">�� ���</param>
/// <returns>ã���� �ش� �ε����� ����, ������ 0�� ����</returns>
int FineId(IdData* _str, int _id, const int _count);
/// <summary>
/// ���α׷� ���� �ϴ� �Լ�
/// </summary>
void MainScreen();
/// <summary>
/// ���� �����ϴ� �Լ�
/// </summary>
/// <param name="">�� ���</param>
/// <param name="">�� ��</param>
void NewId(IdData*, int&);
/// <summary>
/// �Ա� �Լ�
/// </summary>
/// <param name="">�� ���</param>
/// <param name="">���� �� �ε���</param>
void Deposit(IdData* _list, const int _count);
/// <summary>
/// ��� �Լ�
/// </summary>
/// <param name="">�� ���</param>
/// <param name="">���� �� �ε���</param>
void Withdraw(IdData* _list, const int _count);
/// <summary>
/// ��ü ������ ���
/// </summary>
/// <param name="">�� ���</param>
/// <param name="">�� ��</param>
void IdDataShow(IdData*, int);