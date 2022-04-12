#pragma once

#include "Account.h"

#define MAX_COUNT 100

typedef Account* ACCOUNT_PTR;


class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* AccountArr;
	int AccountLen;
	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& _arr) {}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& _arr) {}
public:
	BoundCheckAccountPtrArray();
	BoundCheckAccountPtrArray(const int& _cusCount);
	~BoundCheckAccountPtrArray();

	ACCOUNT_PTR& operator[] (int _idx);
	ACCOUNT_PTR operator[] (int _idx) const;
};

