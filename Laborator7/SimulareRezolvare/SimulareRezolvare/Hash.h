#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
class Hash
{
public:
	virtual int HashFromString(const char* sir) = 0;
};