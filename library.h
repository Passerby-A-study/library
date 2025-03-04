#pragma once
#include<string>
class Book;
typedef	std::string string;
class Person :public Get {
	string P_NAME;
	string P_ID;
public:
	Person();
	virtual void GetName();
	virtual void GetId();
};

class Borrow {
public:
	virtual void markBorrow() = 0 ;
	virtual void markReturn() = 0 ;
};
class Get {
public:
	virtual void GetName() = 0;
	virtual void GetId() = 0;
};

class Admin :public Person {
public:
	Admin() :Person() {}
	void AddBook(Book&b);
};
class User :public Person {
public:
	User() :Person() {}
	void BorrowBook(Book& b);
	void ReturnBook(Book& b);

};
class Book :public Borrow{
private:
	string B_NAME;
	string B_ID;
	bool isBorrowed;
	//int PublicYear;
	//string Author;
	//int BorrowYear;
	//int BorrowMonth;
	//int BorrowDay;
public:
	//Book(const string& bn="None", const string& bid="!0000",bool ib=false/*, int py = 0, const string& a = "None",
	//	int y=0, int m=0, int d=0*/) :B_NAME(bn), B_ID(bid),isBorrowed(ib)/*, PublicYear(py),
	//	Author(a), BorrowYear(y), BorrowMonth(m), BorrowDay(d)*/ {}
	explicit Book(bool ib = false/*, int py, string& a,int y, int m, int d*/) ;
	virtual void markBorrow() ;
	virtual void markReturn() ;
	virtual void GetName();
	virtual void GetId();
	bool ShowBorrow() { return isBorrowed; }
	friend void ShowAll(Book& b);
	friend void Admin::AddBook(Book& b);
};
void markBorrow(Borrow& b);
void markReturn(Borrow& b);
