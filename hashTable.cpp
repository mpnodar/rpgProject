#include "hashTable.h"
hashTable::~hashTable()
{
	delete hasher;
}

hashTable::hashTable(int size)
{
	table.resize(size, nullptr);
	tableSize = size;
	hasher = new Hasher(size);
}

int hashTable::Hash(std::string key)
{
	return hasher->hash(key);
}

hashNode* hashTable::search(std::string key)
{

	int hash = Hash(key);
	if (table[hash] == nullptr) {
		return nullptr;
	}
	Node* n = table[hash];
	do {
		if (n->getData()->getKey() == key) {
			return n->getData();
		}
		if (n->getNextNode() == nullptr) {
			return nullptr;
		}
		n = n->getNextNode();
	} while (true);
}

void hashTable::add(hashNode* hNode)
{
	Node* n = new Node(hNode);
	int hash = Hash(hNode->getKey());
	if (table[hash] == nullptr) {
		table[hash] = n;
	}
	else {
		n->setNextNode(table[hash]);
		table[hash] = n;
	}
}

hashNode* hashTable::remove(std::string key)
{
	int hash = Hash(key);
	if (table[hash] == nullptr) {
		return nullptr;
	}
	if (table[hash]->getData()->getKey() == key) {
		hashNode* hNode = table[hash]->getData();
		table[hash]->setData(NULL);
		delete table[hash];
		table[hash] = nullptr;
		return hNode;
	}
	Node* nPrev = table[hash];
	Node* n = nPrev->getNextNode();
	if (n == nullptr) {
		return nullptr;
	}
	do {
		if (n->getData()->getKey() == key) {
			break;
		}
		if (n->getNextNode() == nullptr) {
			return nullptr;
		}
		nPrev = n;
		n = n->getNextNode();
	} while (true);
	nPrev->setNextNode(n->getNextNode());
	hashNode* hNode = n->getData();
	n->setData(NULL);
	delete n;
	return hNode;
}
