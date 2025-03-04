#include"library.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

Person::Person() {
	GetName();
	GetId();
	cout << endl << "Welcome "<<P_NAME<<" !" << endl;
}
void Person::GetName() {
	cout << "pls Enter Your Name : ";
	cin >> P_NAME;
}
void Person::GetId() {
	cout << endl << "pls Enter Your Id : ";
	cin >> P_ID;
}
//------------------------------------------
void Book::GetName() {
	cout << "pls Enter The Name of Book : ";
	cin >> B_NAME;
}
void Book::GetId() {
	cout << endl << "pls Enter The Id of Book : ";
	cin >> B_ID;
}
Book::Book(bool ib) :isBorrowed(ib) {
	GetName();
	GetId();
	cout << endl << B_NAME << " is Loaded! " << endl;
}
void Book::markBorrow() {
	isBorrowed = true;
}
void Book::markReturn() {
	isBorrowed = false;
}
//-------------------------------------
void Admin::AddBook(Book& b) {

}
//-------------------------------------
void User::BorrowBook(Book& b) {

}
void User::ReturnBook(Book& b) {

}
//-------------------------------------
void markBorrow(Borrow& b) {
	b.markBorrow();
}
void markReturn(Borrow& b) {
	b.markReturn();
}
