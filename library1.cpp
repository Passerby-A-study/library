#include"library.h"

//=============Admin===================
void Admin::AddBook(Library& Li) {
	string name;
	string id;
	cout << "Pls Enter the Name of Book: " << endl;
	cin >> name;
	cout << "Pls Enter the ID of Book: " << endl;
	cin >> id;
	Book* p = new Book(name, id);
	Li.Add(p);
}
void Admin::Show(Library & Li) {
	cout << "BookShelter: " << endl;
	cout << "Book_Name" << "        " << "Book_ID"<<"          " << "Status" << endl;
	Li.Show();
}
int Admin::PrintAdminMenu(Library& Li) {
	cout << "Welcome " <<GetName()<<" !" << endl;
	cout << "1 : Show the Books in the Shelter" << endl;
	cout << "2 : Add Book" << endl;
	cout << "Choose Your Identity(Enter the Number, Q / q to Quit):" << endl;
	int choice;
	cin >> choice;
	if (!cin) {
		cout << "Bye! ";
		return 0;
	}
	return choice;
}
void Admin::Choose(Library& Li) {
	while (1) {
		int choice = PrintAdminMenu(Li);
		switch (choice) {
		case 1:
			Show(Li);
			break;
		case 2:
			AddBook(Li);
			break;
		case 0:
			return;
		}
	}
}
//===============Library=================
void Library::Add(Book* b) {
	BookShelter.push_back(b);
	delete b;
}
void Library::Show() {
	for (auto book : BookShelter) {
		cout << book->GetName() << "       " << book->GetID() << "         " << book->GetStatus() << endl;
	}
}
bool Library::isBorrow(string& s) {
	if (s == "q"||s=="Q")
		return true;
	for (auto book : BookShelter) {
		if (book->GetID() == s) {
			if (book->GetStatus() == false) {
				book->ChangeStatus();
				cout << "Successful! " << endl;
				return true;
			}
			else {
				cout << "Failed, the book is Borrowed. Try Again: " << endl;
				return false;
			}

		}
	}
	cout << "Do not found, Try Again: " << endl;
	return false;
}
//================Client==================
void User::Show(Library& Li) {
	cout << "BookShelter: " << endl;
	cout << "Book_Name" << "        " << "Book_ID" << "          " << "Status" << endl;
	Li.Show();
}
void User::BorrowBook(Library& Li) {
	string b;
	cout << "Pls Enter the ID of Book( q / Q to Quit): ";
	cin >> b;
	while (Li.isBorrow(b) == false) {
		cout << "Pls Enter the ID of Book( q / Q to Quit): ";
		cin >> b;
	}
}
int User::PrintUserMenu(Library& Li) {
	cout << "Welcome " << GetName() << " !" << endl;
	cout << "1 : Show the Books in the Shelter" << endl;
	cout << "2 : Borrow Book" << endl;
	cout << "Enter Your Choice (Enter the Number, Q / q to Quit):" << endl;
	int choice;
	cin >> choice;
	if (!cin) {
		cout << "Bye! ";
		return 0;
	}
	return choice;
}
void User::Choose(Library& Li) {
	while (1) {
		int choice = PrintUserMenu(Li);
		switch (choice) {
		case 1:
			Show(Li);
			break;
		case 2:
			BorrowBook(Li);
			break;
		case 0:
			return;
		}
	}
}

//=================Menu================
void PrintMenu() {
	cout << ":";
}
int PrintLogin() {
	cout << "Pls Login"<<endl;
	cout << "1 : Admin" << endl;
	cout << "2 : User" << endl;
	cout << "Enter Your Choice (Enter the Number, Q / q to Quit):" << endl;
	int choice;
	cin >> choice;
	if (!cin) {
		cout << "Bye! ";
		return 0;
	}
	return choice;
}
