#include "admin.h"
#include "staff.h"
#include "customer.h"
int main() {
	int input{};
	while (true) {
		cout << "LOGIN AS:" << endl << endl;
		cout << "1 - Admin" << endl;
		cout << "2 - Staff" << endl;
		cout << "3 - Customer" << endl;
		cout << "4 - Exit" << endl;
		cin >> input;
		if (input == 1) {
			admin();
		}
		else if (input == 2) {
			staff();
		}
		else if (input == 3) {
			customer();
		}
		else {
			break;
		}

	}
	return 0;
}