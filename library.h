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
	bool isBorrow(string& s);
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
	virtual bool GetStatus() { return isBorrow; }
	virtual void ChangeStatus() { isBorrow=!isBorrow; }
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
	Admin(string& name, string& id) :Person(name,id) {}
	void AddBook(Library& Li);
	void Show(Library& Li);
};
//=============Client==================
class User :public Person {
public:
	User(string& name, string& id) :Person(name, id) {}
	void BorrowBook(Library& Li);
	void Show(Library& Li);
};

//=============Menu=====================
void PrintMenu();
int PrintLogin();