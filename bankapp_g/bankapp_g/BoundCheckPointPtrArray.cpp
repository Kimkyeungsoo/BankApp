#include "BoundCheckPointPtrArray.h"

#include <iostream>

BoundCheckPointPtrArray::BoundCheckPointPtrArray()
	:AccountLen(MAX_COUNT)
{
	AccountArr = new AccountPointer[AccountLen];
}

BoundCheckPointPtrArray::BoundCheckPointPtrArray(const int& _AccountLen)
	: AccountLen(_AccountLen)
{
	AccountArr = new AccountPointer[_AccountLen];
}

BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
	delete[]AccountArr;
}

AccountPointer& BoundCheckPointPtrArray::operator[](int _idx)
{
	if (_idx < 0 || _idx > AccountLen)
	{
		std::cout << "실패" << std::endl;
		exit(1);
	}
	return AccountArr[_idx];
}

AccountPointer BoundCheckPointPtrArray::operator[](int _idx) const
{
	if (_idx < 0 || _idx > AccountLen)
	{
		std::cout << "실패" << std::endl;
		exit(1);
	}
	return AccountArr[_idx];
}