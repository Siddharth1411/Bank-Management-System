#include "BST_Tree.h"
BST_Tree::BST_Tree() {
	root = nullptr;
}
void BST_Tree::add_account(string name, string address, int acc, int pass, int bal) {
	//adding acc. details to server
	ofstream write;
	write.open("server.txt", ios::app);
	write << name << endl << address << endl << acc << endl << pass << endl << bal << endl;
	write.close();

	ofstream write_transaction;
	write_transaction.open("transaction.txt", ios::app);
	write_transaction << acc << endl;
	write_transaction.close();

	//adding acc. to BST
	add_node(name, address, acc, pass, bal);
}

BST_Node*  BST_Tree::delete_account(BST_Node* root, int acc) {
	if (root == nullptr) {
		cout << "tree is empty" << endl;
	}
	else if (acc < root->account_number) {
		root->left = delete_account(root->left, acc);
	}
	else if (acc > root->account_number) {
		root->right = delete_account(root->right, acc);
	}
	else {
		if (root->left && root->right) {
			findMax(root->left);
			root->account_number = v.back();
			v.clear();
			root->left = delete_account(root->left, root->account_number);
		}
		else {
			BST_Node* temp = root;
			if (root->left == nullptr) {
				root = root->right;
			}
			else {
				root = root->left;
			}
			delete temp;
		}
	}
	return root;
}

void BST_Tree::findMax(BST_Node* root) {
	if (root) {
		findMax(root->left);
		v.push_back(root->account_number);
		findMax(root->right);
	}
}

void BST_Tree::load_server() {
	//cout << "entering load_server" << endl;
	ifstream read;
	//cout << "ifstream read" << endl;
	read.open("server.txt");
	//cout << "read.open" << endl;
	if (!read.is_open()) {
		//cout << "Error opening file" << endl;
		return;
	}
	//cout << "file opened" << endl;
	string name;
	string address;
	int acc{};
	int pass{};
	int bal{};
	while (!read.eof()){
		//cout << "inside loop" << endl;
		read >> name;
		if (read.eof()) {
			//cout << "file ends" << endl;
			break;
		}
		read >> address;
		read >> acc;
		read >> pass;
		read >> bal;
		//constructing BST
		add_node(name, address, acc, pass, bal);
	}
	read.close();
	//cout << "outside loop" << endl;
}

void BST_Tree::add_node(string name, string address, int acc, int pass, int bal) {
	BST_Node* temp = new BST_Node(name, address, acc, pass, bal);
	BST_Node* curr = root;
	if (root == nullptr) {
		root = temp;
	}
	else {
		while (true) {
			if (acc < curr->account_number) {
				if (curr->left == nullptr) {
					curr->left = temp;
					break;
				}
				curr = curr->left;
			}
			else {
				if (curr->right == nullptr) {
					curr->right = temp;
					break;
				}
				curr = curr->right;
			}
		}
	}
}

void BST_Tree::update_server_wrapper(BST_Node* root) {
	//cout << "update_server_wrapper" << endl;
	ofstream write;
	write.open("server.txt", ios::trunc);

	if (!write.is_open()) {
		//cout << "Error opening file" << endl;
		return;
	}

	update_server(root, write);
	write.close();
}
void BST_Tree::update_server(BST_Node* root, ofstream& write) {
	//cout<<"update_server"<<endl;
	if (root) {
		update_server(root->left, write);
		//cout << "about to write" << endl;
		write << root->name << '\n'
			<< root->address << '\n'
			<< root->account_number << '\n'
			<< root->password << '\n'
			<< root->balance << '\n';
		//cout << "written" << endl;
		update_server(root->right, write);
	}
}
BST_Node* BST_Tree::search(BST_Node* root, int acc) {
	if (root == nullptr)
		return nullptr;
	else if (acc < root->account_number)
		return search(root->left, acc);
	else if (acc > root->account_number)
		return search(root->right, acc);
	return root;
}


void BST_Tree::transfer(int sender_acc, int receiver_acc, int amt) {
	//transaction in bst
	BST_Node* sender = search(root, sender_acc);
	sender->balance = sender->balance - amt;
	BST_Node* receiver = search(root, receiver_acc);
	receiver->balance = receiver->balance + amt;
	update_server_wrapper(root);

	//transaction file
	vector<int>data;
	ifstream read;
	read.open("transaction.txt");
	int val{};
	while (!read.eof()) {
		read >> val;
		if (read.eof()) {
			break;
		}
		data.push_back(val);
		if (val == sender_acc) {
			data.push_back((-1 * amt));
		}
		else if (val == receiver_acc) {
			data.push_back(amt);
		}
	}
	//cout << data.size() << endl;
	read.close();
	ofstream write;
	write.open("transaction.txt", ios::trunc);
	for (int i = 0; i < data.size(); i++) {
		write << data[i] << '\n';
	}
	write.close();
}

void BST_Tree::withdraw(int acc, int amt) {
	//in bst
	BST_Node* account = search(root, acc);
	account->balance = account->balance - amt;
	update_server_wrapper(root);

	ifstream read;
	read.open("transaction.txt");
	vector<int>data;
	int val{};
	while (!read.eof()) {
		read >> val;
		data.push_back(val);
		if (val == acc) {
			data.push_back((-1 * amt));
		}
	}
	read.close();
	ofstream write;
	write.open("transaction.txt", ios::trunc);
	for (int i = 0; i < data.size(); i++) {
		write << data[i] <<'\n';
	}
	write.close();
}

void BST_Tree::deposit(int acc, int amt) {
	//in bst
	BST_Node* account = search(root, acc);
	account->balance = account->balance + amt;
	update_server_wrapper(root);

	ifstream read;
	read.open("transaction.txt");
	vector<int>data;
	int val{};
	while (!read.eof()) {
		read >> val;
		data.push_back(val);
		if (val == acc) {
			data.push_back(amt);
		}
	}
	read.close();
	ofstream write;
	write.open("transaction.txt", ios::trunc);
	for (int i = 0; i < data.size(); i++) {
		write << data[i] << '\n';
	}
	write.close();
}

void BST_Tree::transaction_history(int acc) {
	vector<int>transaction_data;
	ifstream read;
	read.open("transaction.txt");
	int val{};
	while (!read.eof()) {
		read >> val;
		if (val == acc) {
			if (read.eof())
				break;
			read >> val;
			while (val < 0 || !search(root, val)) {
				transaction_data.push_back(val);
				if (read.eof())
					break;
				read >> val;
			}
			break;
		}
	}
	cout << acc << endl;
	if (transaction_data.size() == 0) {
		cout << "no transaction history" << endl;
		return;
	}
	cout << "trasaction history:" << endl;
	for (int i = 0; i < transaction_data.size(); i++) {
		cout << transaction_data[i] << endl;
	}
}

void BST_Tree::print_info(BST_Node* root) {
	if (root) {
		print_info(root->left);
		cout << root->name << endl;
		cout << root->address << endl;
		cout << root->account_number << endl;
		cout << root->password << endl;
		cout << root->balance << endl;
		print_info(root->right);
	}
}

void BST_Tree::edit_account(string new_name, string new_address, int acc, int new_pass) {
	BST_Node* account = search(root, acc);
	account->name = new_name;
	account->address = new_address;
	account->password = new_pass;
	update_server_wrapper(root);
}
