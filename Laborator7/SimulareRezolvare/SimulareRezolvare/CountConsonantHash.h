#pragma once
#include "Hash.h"
class CountConsonantHash :public Hash
{
public:
	int HashFromString(const char* sir)override;
};