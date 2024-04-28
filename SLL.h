#pragma once
#include "Node.h"
#include "hashNode.h"

class SLL
{
private:
	Node *head;
	Node *index;
public:
	SLL(hashNode* data);
	Node* getFirst();
	Node* getLast();
	Node* getCurrent();
	void pushback(Node*);
	void insertAfter(Node*, Node*);
	void pushBack(Node*);
	void pushFront(Node* newNode);
	void deleteCurrent();
	Node* popBack();
	Node* popFront();
	Node* getBefore(Node*);
	void setCurrent(Node*);
};

