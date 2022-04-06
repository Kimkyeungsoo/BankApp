#pragma once

#include <iostream>

// 구조체 배열로 만들어야합니다.
typedef struct IdData
{
	int ID;
	int money;
	char name[20];
} IdData;
/// <summary>
/// 계좌 검색하는 함수
/// </summary>
/// <param name="">고객 명단</param>
/// <returns>찾으면 해당 인덱스를 리턴, 없으면 0을 리턴</returns>
int FineId(IdData* _str, int _id, const int _count);
/// <summary>
/// 프로그램 동작 하는 함수
/// </summary>
void MainScreen();
/// <summary>
/// 계좌 개설하는 함수
/// </summary>
/// <param name="">고객 명단</param>
/// <param name="">고객 수</param>
void NewId(IdData*, int&);
/// <summary>
/// 입금 함수
/// </summary>
/// <param name="">고객 명단</param>
/// <param name="">변경 할 인덱스</param>
void Deposit(IdData* _list, const int _count);
/// <summary>
/// 출금 함수
/// </summary>
/// <param name="">고객 명단</param>
/// <param name="">변경 할 인덱스</param>
void Withdraw(IdData* _list, const int _count);
/// <summary>
/// 전체 고객정보 출력
/// </summary>
/// <param name="">고객 명단</param>
/// <param name="">고객 수</param>
void IdDataShow(IdData*, int);