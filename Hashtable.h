#pragma once
#include "Node.h"
#include "Node_1.h"

class Hashtable {
public:
	Node* start;
	Hashtable();
	void starthash();
	void loadhashtable();
	void add(int, int);
	void add_node(int, int);
	bool match(int, int);
	void display();
	void display_passwords();
	void delete_password(int);
	void edit_password(int, int);
};
