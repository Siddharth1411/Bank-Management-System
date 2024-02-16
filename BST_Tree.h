#pragma once
#include "BST_Node.h"
#include "Hashtable.h"
class BST_Tree {
	vector<int>v;
public:
	BST_Node* root;
	BST_Tree();
	void add_account(string, string, int, int, int);
	void add_node(string, string, int, int, int);
	void load_server();
	BST_Node* delete_account(BST_Node*, int);
	void findMax(BST_Node*);
	void update_server_wrapper(BST_Node*);
	void update_server(BST_Node*, ofstream&);
	void transfer(int, int, int);
	BST_Node* search(BST_Node*, int);
	void withdraw(int, int);
	void deposit(int, int);
	void transaction_history(int);
	void print_info(BST_Node*);
	void edit_account(string, string, int, int);
};
