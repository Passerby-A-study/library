#pragma once
#include<string>
#include<vector>
using std::string;
using std::vector;
class Book;

//============Library=================

class Library {
private:
	vector<Book> BookShelter;
public:
	void Add(Book& b);
};


//=============Book====================
class Book {
private:
	string BookName;
	string BookID;
public:
	Book(string&name,string&id):BookName(name),BookID(id){}
};
//=============Person==================
class Person {
private:
	string UserName;
	string UserID;
public:
	Person(string& name, string& id) :UserName(name), UserID(id) {}
};
//=============Admin===================
class Admin:public Person {
public:
	Admin();
	void AddBook();
	void Show();
};
//=============Client==================
class User :public Person {
public:
	User();
	void BorrowBook();
};