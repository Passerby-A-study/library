#include"library.h"
#include <iomanip>
#include <cstdlib> 
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
void Admin::Show(Library& Li) {
	cout << "BookShelter: " << endl;
	cout << std::setw(20) << "Book_Name" << std::setw(20) << "Book_ID" << std::setw(20) << "Status" << endl;
	cout << std::setfill('-') << std::setw(60) << "" << std::setfill(' ') << endl; // 分隔线
	Li.Show();
	cout << "\n";
}
int Admin::PrintAdminMenu(Library& Li) {
	cout << "Welcome " <<GetName()<<" !" << endl;
	cout << "1 : Show the Books in the Shelter" << endl;
	cout << "2 : Add Book" << endl;
	cout << "Pls Enter Your Choice (Enter the Number, Q / q to Quit):" << endl;
	int choice;
	cin >> choice;
	if (!cin) {
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
	cout << "\nBook added successfully!\n\n";
}
void Library::Show() {
	for (auto book : BookShelter) {
		cout << std::setw(20) << book->GetName() << std::setw(20) << book->GetID() << std::setw(20) << (book->GetStatus() ? "Borrowed" : "Available") << endl;
	}
	
}
bool Library::isBorrow(string& s) {
	if (s == "q"||s=="Q")
		return true;
	for (auto book : BookShelter) {
		if (book->GetID() == s) {
			if (book->GetStatus() == false) {
				book->ChangeStatus();
				cout << "Borrow Successfully! " << endl;
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
bool Library::isReturn(string& s) {
	if (s == "q"||s=="Q")
		return true;
	for (auto book : BookShelter) {
		if (book->GetID() == s) {
			if (book->GetStatus() == true) {
				book->ChangeStatus();
				cout << "Return Successfully! " << endl;
				return true;
			}
			else {
				cout << "Failed, You Hadn't Borrow the Book. Try Again: " << endl;
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
	cout << std::setw(20) << "Book_Name" << std::setw(20) << "Book_ID" << std::setw(20) << "Status" << endl;
	cout << std::setfill('-') << std::setw(60) << "" << std::setfill(' ') << endl; // 分隔线
	Li.Show();
	cout << "\n";
}
void User::BorrowBook(Library& Li) {
	string b;
	cout << "Pls Enter the ID of Book( q / Q to Quit): ";
	cin >> b;
	while (Li.isBorrow(b) == false) {
		cin >> b;
	}

}
void User::ReturnBook(Library& Li) {
	string b;
	cout << "Pls Enter the ID of Book( q / Q to Quit): ";
	cin >> b;
	while (Li.isReturn(b) == false) {
		cin >> b;
	}

}
int User::PrintUserMenu(Library& Li) {
	cout << "Welcome " << GetName() << " !" << endl;
	cout << "1 : Show the Books in the Shelter" << endl;
	cout << "2 : Borrow Book" << endl;
	cout << "3 : Return Book" << endl;
	cout << "Pls Enter Your Choice (Enter the Number, Q / q to Quit):" << endl;
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
		case 3:
			ReturnBook(Li);
			break;
		case 0:
			return;
		}
	}
}

//=================Menu================

int PrintLogin() {
	cout << "Pls Login" << endl;
	cout << "1 : Admin" << endl;
	cout << "2 : User" << endl;
	cout << "Choose Your Identity (Enter the Number, Q / q to Quit):" << endl;
	string input;
	cin >> input;
	if (input == "q" || input == "Q") {
		return 0;
	}
	try {
		return std::stoi(input);
	}
	catch (...) {
		return 0;
	}
}
