#pragma once
#include "hashNode.h"
class Node
{
private:
	hashNode* data = nullptr;
	Node *nextNode = nullptr;
public:
	Node();
	Node(hashNode* newData);
	Node(Node* ptr);
	hashNode* getData();
	void setData(hashNode*);
	Node* getNextNode();
	void setNextNode(Node*);
};

