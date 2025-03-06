#include"library.h"
int main() {
	Library Li;
	int choice = PrintLogin();
	switch (choice) {
	case 1: {
		string name;
		string id;
		cout << "Pls Enter Your Name: " << endl;
		cin >> name;
		cout << "Pls Enter Your ID: " << endl;
		cin >> id;
		Admin A = Admin(name, id);
		A.Choose(Li);
		cout << "Bye !" << endl;
		return 0;
	}
	case 2: {
		string name;
		string id;
		cout << "Pls Enter Your Name: " << endl;
		cin >> name;
		cout << "Pls Enter Your ID: " << endl;
		cin >> id;
		User U = User(name, id);
		U.Choose(Li);
		cout << "Bye !" << endl;
		return 0;
	}
	case 0:
		return 0;
	}
	return 0;
}