#include "SLL.h"
#include "iostream"

SLL::SLL(hashNode* data) {
	head = new Node(data);
	index = head;
}

Node* SLL::getLast()
{
	Node* localIndex = head;
	if (localIndex == nullptr) {
		return nullptr;
	}

	while (localIndex->getNextNode()) {
		if (!localIndex->getNextNode()) {
			return localIndex;
		}
		localIndex = localIndex->getNextNode();
	}

	return localIndex;
}

Node* SLL::getCurrent()
{
	return index;
}

void SLL::pushBack(Node *n)
{
	pushback(n);
	/*getLast()->setNextNode(n);
	index = head;*/
}

void SLL::deleteCurrent()
{
	if (index == head) {
		head = head->getNextNode();
		index = head;
	}
	else {
		Node* previous = getBefore(index);
		previous->setNextNode(index->getNextNode());
		if (previous->getNextNode() != nullptr) {
			index = previous->getNextNode();
		}
		else {
			index = head;
		}
	}
}

Node* SLL::popBack()
{
	Node *lastNode = getLast();
	Node *before = getBefore(lastNode);
	before->setNextNode(nullptr);
	index = getLast();
	return lastNode;
}

Node* SLL::popFront()
{
	Node *oldHead = head;
	Node *newHead = head->getNextNode();
	index = newHead;
	head = newHead;
	return oldHead;
}

Node* SLL::getBefore(Node* n)
{
	if (n == head) {
		return nullptr;
	}
	Node* tempIndex = head;
	while ((tempIndex->getNextNode() != n) && (tempIndex->getNextNode() != nullptr)) {
		tempIndex = tempIndex->getNextNode();
	}
	if (tempIndex->getNextNode() == nullptr) {
		return nullptr;
	}
	return tempIndex;
}

void SLL::setCurrent(Node* n)
{
	index = n;
}

void SLL::insertAfter(Node* prevNode, Node* newNode)
{

	if (prevNode->getNextNode() == nullptr) {
		prevNode->setNextNode(newNode);
	}
	else {
		Node* tempNode = prevNode->getNextNode();
		newNode->setNextNode(tempNode);
		prevNode->setNextNode(newNode);
	}
	index = newNode;
}

void SLL::pushback(Node* newNode)
{
	getLast()->setNextNode(newNode);
	index = head;
}

Node* SLL::getFirst()
{
	return head;
}

void SLL::pushFront(Node* newNode) {
	newNode->setNextNode(head);
	head = newNode;
	index = head;
}

