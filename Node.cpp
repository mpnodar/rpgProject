#include "Node.h"

Node::Node() {
	data = nullptr;
	nextNode = nullptr;
}

Node::Node(hashNode* newData) {
	data = newData;
}

Node::Node(Node* ptr) : data(ptr->data), nextNode(ptr->nextNode) {}

hashNode* Node::getData()
{
	return data;
}

void Node::setData(hashNode* input)
{
	data = input;
}

Node* Node::getNextNode()
{
	return nextNode;
}

void Node::setNextNode(Node *n)
{
	nextNode = n;
}
