#include "Hasher.h"
#include <iostream>

int Hasher::hash(std::string value)
{
	int sum = 0;
	
	for (auto c : value) {
		sum += c;
	}
	return sum % maxHashNumber;
}

Hasher::Hasher(int maxHashValue)
{	
	maxHashNumber = maxHashValue;
}