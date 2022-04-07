#include "HashManager.h"

HashManager::HashManager()
{
	size = 0;
}

Hash*& HashManager::operator[](const char* sir)
{
	hashes[size].nume = sir;
	size++;
	return hashes[size - 1].hash;
}

void HashManager::print_hashes(const char* sir)
{
	for (unsigned i = 0; i < size; i++)
		printf("%s %d\n", hashes[i].nume, hashes[i].hash->HashFromString(sir));
}
