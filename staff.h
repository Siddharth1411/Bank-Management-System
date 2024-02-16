#pragma once
#include "Hashtable.h"
#include "BST_Tree.h"
void staff() {
	BST_Tree t;
	Hashtable h;
	t.load_server();
	h.loadhashtable();
	int input{};
	while (true) {
		cout << "Welcome Staff" << endl;
		cout << "Press 1 to transfer" << endl;
		cout << "Press 2 to withdraw" << endl;
		cout << "Press 3 to deposit" << endl;
		cout << "Press 4 to see transaction history" << endl;
		cout << "Press 5 to exit" << endl;
		cin >> input;
		if (input == 1) {
			int sender_acc{};
			int receiver_acc{};
			int amt{};
			cout << "Enter sender account no." << endl;
			cin >> sender_acc;
			cout << "Enter receiver account no." << endl;
			cin >> receiver_acc;
			cout << "Enter amount" << endl;
			cin >> amt;
			t.transfer(sender_acc, receiver_acc, amt);
			cout << "transfer of amt successfull" << endl;
		}
		else if (input == 2) {
			int acc{};
			int amt{};
			cout << "Enter account no." << endl;
			cin >> acc;
			cout << "Enter amount" << endl;
			cin >> amt;
			t.withdraw(acc, amt);
		}
		else if (input == 3) {
			int acc{};
			int amt{};
			cout << "Enter account no." << endl;
			cin >> acc;
			cout << "Enter amount" << endl;
			cin >> amt;
			t.deposit(acc, amt);
		}
		else if (input == 4) {
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
