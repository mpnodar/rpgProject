#pragma once
#include "hashNode.h"
#include "Node.h"
#include "Hasher.h"
#include <vector>
#include <iostream>
class hashTable
{
private:
	std::vector<Node*> table;
	int tableSize = 0;
	Hasher* hasher = NULL;
public:
	~hashTable();
	hashTable(int size);
	int Hash(std::string key);
	hashNode* search(std::string key);
	void add(hashNode*);
	hashNode* remove(std::string key);
};

