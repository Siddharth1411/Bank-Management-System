#pragma once
#include "BST_Tree.h"
#include "Hashtable.h"
void customer() {
	BST_Tree t;
	Hashtable h;
	t.load_server();
	h.loadhashtable();
	int input{};
	while (true) {
		cout << "Press 1 - to see account details" << endl;
		cout << "Press 2 - to see transaction history" << endl;
		cout << "Press 3 - to exit" << endl;
		cin >> input;
		if (input == 1) {
			int acc{};
			cout << "Enter account no." << endl;
			cin >> acc;
			BST_Node* account = t.search(t.root, acc);
			cout << "Account details:" << endl;
			cout << "Name:" << " " << account->name << endl;
			cout << "Address:" << " " << account->address << endl;
			cout << "Account no:" << " " << account->account_number << endl;
			cout << "Password:" << " " << account->password << endl;
			cout << "Balance:" << " " << account->balance << endl;
		}
		else if (input == 2) {
			int acc{};
			cout << "Enter account no." << endl;
			cin >> acc;
			t.transaction_history(acc);
		}
		else {
			break;
		}
	}
}
