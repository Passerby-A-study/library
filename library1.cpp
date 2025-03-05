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
string GetName();
string GetID();
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