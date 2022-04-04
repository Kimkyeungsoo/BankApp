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
int FineId(IdData*);
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
void Deposit(IdData*, int);
/// <summary>
/// ��� �Լ�
/// </summary>
/// <param name="">�� ���</param>
/// <param name="">���� �� �ε���</param>
void Withdraw(IdData*, int);
/// <summary>
/// ��ü ������ ���
/// </summary>
/// <param name="">�� ���</param>
/// <param name="">�� ��</param>
void IdDataShow(IdData*, int);