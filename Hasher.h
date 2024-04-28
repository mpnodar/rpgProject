#pragma once
#include <random>
#include <cmath>
class Hasher
{
private:
	int hashNumber = 0;
	int maxHashNumber = 0;
public:
	int hash(std::string);
	Hasher(int);
};

