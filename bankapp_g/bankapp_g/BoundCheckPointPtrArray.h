#pragma once

#include "Account.h"

#define MAX_COUNT 100

typedef Account* AccountPointer;


class BoundCheckPointPtrArray
{
private:
	AccountPointer* AccountArr;
	int AccountLen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& _arr) {}
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& _arr) {}
public:
	BoundCheckPointPtrArray();
	BoundCheckPointPtrArray(const int& _cusCount);
	~BoundCheckPointPtrArray();

	AccountPointer& operator[] (int _idx);
	AccountPointer operator[] (int _idx) const;
};

