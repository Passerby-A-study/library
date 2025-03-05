#pragma once
#include<string>
#include<vector>
#include<iostream>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
class Book;
class Admin;
class User;
//============Library=================

class Library {
private:
	vector<Book*> BookShelter;
	vector<Admin*> LibAdmin;
	vector<User*> LibUser;
public:
	void Add(Book* b);
	void Show();
};
//=============Get=====================
class Get {
public:
	virtual string GetName() = 0;
	virtual string GetID() = 0;
};

//=============Book====================
class Book {
private:
	string BookName;
	string BookID;
	bool isBorrow;
public:
	Book(string&name,string&id,bool ib=false):BookName(name),BookID(id),isBorrow(ib){}
	virtual string GetName() { return BookName; }
	virtual string GetID() { return BookID; };
	virtual string GetStatus() { return BookID; };
};
//=============Person==================
class Person {
private:
	string UserName;
	string UserID;
public:
	Person(string& name, string& id) :UserName(name), UserID(id) {}
	Person(){}
};
//=============Admin===================
class Admin:public Person {
public:
	Admin(string& name, string& id) :Person(name,id) {}
	void AddBook(Library& Li);
	void Show(Library& Li);
};
//=============Client==================
class User :public Person {
public:
	User();
	void BorrowBook();
};