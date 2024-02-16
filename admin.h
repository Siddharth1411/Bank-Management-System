#pragma 
#include "BST_Tree.h"
#include "Hashtable.h"
using namespace std;
void admin() {
	BST_Tree t;
	Hashtable h;
	t.load_server();
	h.loadhashtable();
	int input{};
	while (true) {
		cout << "Welcome Admin" << endl << endl;
		cout << "Press 1 - to add account" << endl;
		cout << "Press 2 - to delete account" << endl;
		cout << "Press 3 - to check all accounts" << endl;
		cout << "Press 4 - see password of all accounts" << endl;
		cout << "Press 5 - edit account" << endl;
		cout << "Press 6 - exit" << endl;
		cin >> input;
		if (input == 1) {
			string name;
			string address;
			int acc{};
			int pass{};
			int bal{};
			cout << "enter name" << endl;
			cin >> name;
			cout << "enter address" << endl;
			cin >> address;
			cout << "enter account no." << endl;
			cin >> acc;
			cout << "enter password" << endl;
			cin >> pass;
			cout << "enter balance" << endl;
			cin >> bal;
			t.add_account(name, address, acc, pass, bal);
			h.add(acc, pass);
			cout << "account successfully added" << endl;
		}
		else if (input == 2) {
			int acc{};
			cout << "Enter account number" << endl;
			cin >> acc;
			t.root = t.delete_account(t.root, acc);
			t.update_server_wrapper(t.root);
			h.delete_password(acc);
		}
		else if (input == 3) {
			t.print_info(t.root);
		}
		else if (input == 4) {
			h.display_passwords();
		}
		else if (input == 5) {
			string name;
			string address;
			int acc{};
			int pass{};
			cout << "Enter account no." << endl;
			cin >> acc;
			cout << "Enter new name" << endl;
			cin >> name;
			cout << "Enter new address" << endl;
			cin >> address;
			cout << "Enter new password" << endl;
			cin >> pass;
			t.edit_account(name, address, acc, pass);
		}
		else {
			break;
		}
	}
}