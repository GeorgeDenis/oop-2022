#pragma once
#include "Hash.h"
class CountVowelsHash :public Hash
{
public:
	int HashFromString(const char* sir)override;
};