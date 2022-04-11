#pragma once
#include "Hash.h"
class HashManager {
	int size;
	struct pair {
		Hash* hash;
		const char* nume;
	};
	pair hashes[20];
public:
	HashManager();
	Hash*& operator[](const char*);
	void print_hashes(const char*);
};