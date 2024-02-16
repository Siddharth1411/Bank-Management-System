#include "Hashtable.h"
#include <iostream>
#include <vector>
using namespace std;

Hashtable::Hashtable() {
	start = nullptr;
}

void Hashtable::starthash() {
	for (int i = 0; i < 12; i++) {
		Node* temp = new Node(i);
		if (start == nullptr) {
			start = temp;
		}
		else {
			Node* curr = start;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
}

void Hashtable::add(int acc, int pass) {
	static int cnt = 0;
	ofstream write;
	write.open("hashtable.txt", ios::app);
	if (cnt > 0) {
		write << endl;
		write << acc << endl << pass;
	}
	else {
		cnt++;
		write << acc << endl << pass;
	}
	write.close();

	//adding the acc. to hashtable
	add_node(acc, pass);
}

bool Hashtable::match(int acc, int pass) {
	bool flag = false;
	int rem = acc % 10; //hashtable key
	Node* curr = start;
	while(curr -> data != rem) {
		curr = curr->next;
	}
	Node_1* curr1 = curr->prev;
	while (curr1 != nullptr) {
		if (curr1->account_number == acc && curr1->password == pass) {
			flag = true;
			break;
		}
		curr1 = curr1->next;
	}
	return flag;
}

void Hashtable::loadhashtable() {
	starthash();
	ifstream read;
	read.open("hashtable.txt");
	if (!read.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	int acc{};
	int pass{};
	while (!read.eof()) {
		read >> acc;
		if (read.eof()) {
			//cout << "end of file 2" << endl;
			break;
		}
		read >> pass;
		//cout << "before add_node" << endl;
		add_node(acc, pass);
		//cout << "after add_node" << endl;
	}
	//cout << "out of loop" << endl;
	read.close();
}

void Hashtable::add_node(int acc, int pass) {
	//cout << "entered add_node" << endl;
	int rem = acc % 10; //hashtable key
	Node_1* temp = new Node_1(acc, pass);
	Node* curr = start;
	while (curr->data != rem) {
		curr = curr->next;
	}
	Node_1* curr1 = curr->prev;
	if (curr1 == nullptr) {
		curr->prev = temp;
		return;
	}
	while (curr1->next != nullptr) {
		curr1 = curr1->next;
	}
	curr1->next = temp;
	//cout << "exited add_node" << endl;
}

void Hashtable::delete_password(int account_no) {
	ifstream read;
	read.open("hashtable.txt");
	vector<int>a;
	vector<int>p;
	int acc{};
	int pass{};
	while (!read.eof()) {
		read >> acc;
		read >> pass;
		if (acc == account_no) {
			continue;
		}
		a.push_back(acc);
		p.push_back(pass);
	}
	read.close();
	ofstream write;
	write.open("temp.txt", ios::app);
	for (int i = 0; i < a.size() - 1; i++) {
		write << a[i] << endl;
		write << p[i] << endl;
	}
	write.close();
	remove("hashtable.txt");
	rename("temp.txt", "hashtable.txt");
}

void Hashtable::display_passwords() {
	Node* curr = start;
	while (curr != nullptr) {
		Node_1* curr1 = curr->prev;
		while (curr1 != nullptr) {
			cout << curr1->account_number << endl;
			cout << curr1->password << endl;
			curr1 = curr1->next;
		}
		curr = curr->next;
	}
}

void Hashtable::edit_password(int acc_no, int new_pass) {
	int rem = acc_no % 10;
	Node* curr = start;
	while (curr->data != rem) {
		curr = curr->next;
	}
	Node_1* curr1 = curr->prev;
	while (curr1->account_number != acc_no) {
		curr1 = curr1->next;
	}
	curr1->password = new_pass;

	ifstream read;
	read.open("hashtable.txt");
	vector<int>a;
	vector<int>p;
	int acc{};
	int pass{};
	while (!read.eof()) {
		read >> acc;
		read >> pass;
		if (acc == acc_no) {
			a.push_back(acc);
			p.push_back(new_pass);
			continue;
		}
		a.push_back(acc);
		p.push_back(pass);
	}
	read.close();
	ofstream write;
	write.open("temp.txt", ios::app);
	for (int i = 0; i < a.size() - 1; i++) {
		write << a[i] << endl;
		write << p[i] << endl;
	}
	write.close();
	remove("hashtable.txt");
	rename("temp.txt", "hashtable.txt");
}