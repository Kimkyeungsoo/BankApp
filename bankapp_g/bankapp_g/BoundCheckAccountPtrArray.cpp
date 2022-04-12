#include "BoundCheckAccountPtrArray.h"

#include <iostream>

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray()
	:AccountLen(MAX_COUNT)
{
	AccountArr = new ACCOUNT_PTR[AccountLen];
}

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(const int& _AccountLen)
	: AccountLen(_AccountLen)
{
	AccountArr = new ACCOUNT_PTR[_AccountLen];
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
	delete[]AccountArr;
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int _idx)
{
	if (_idx < 0 || _idx > AccountLen)
	{
		std::cout << "실패" << std::endl;
		exit(1);
	}
	return AccountArr[_idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int _idx) const
{
	if (_idx < 0 || _idx > AccountLen)
	{
		std::cout << "실패" << std::endl;
		exit(1);
	}
	return AccountArr[_idx];
}