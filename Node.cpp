#include "Node.h"

Node::Node() {
	next = nullptr;
	prev = nullptr;
	data = 0;
}

Node::Node(int data) {
	next = nullptr;
	prev = nullptr;
	this->data = data;
}