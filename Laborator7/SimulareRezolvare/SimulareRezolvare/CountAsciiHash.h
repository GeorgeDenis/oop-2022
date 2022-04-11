#pragma once
#include "Hash.h"
class CountAsciiHash : public Hash
{
public:
	int HashFromString(const char* sir)override;
};