#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node_1.h"
using namespace std;

class Node {
public:
	Node* next;
	Node_1* prev;
	int data;

	Node();
	Node(int);
};

