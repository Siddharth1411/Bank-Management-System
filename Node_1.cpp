#include "Node_1.h"

Node_1::Node_1() {
	next = nullptr;
	account_number = 0;
	password = 0;
}

Node_1::Node_1(int account_number, int password) {
	next = nullptr;
	this->account_number = account_number;
	this->password = password;
}