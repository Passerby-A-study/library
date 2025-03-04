#pragma once
#include<string>
typedef	std::string string;
class Person {
	string P_NAME;
	string P_ID;
public:
	Person(const string& name="Null", const string& id="00000") :P_NAME(name), P_ID(id) {}
	Person(string& name, string& id);
	virtual ~Person()=0 {}
};

class Borrow {
public:
	virtual void markBorrow(Borrow& b) = 0 ;
	virtual void markReturn(Borrow& b) = 0 ;
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
	Book(const string& bn="None", const string& bid="!0000",bool ib=false/*, int py = 0, const string& a = "None",
		int y=0, int m=0, int d=0*/) :B_NAME(bn), B_ID(bid),isBorrowed(ib)/*, PublicYear(py),
		Author(a), BorrowYear(y), BorrowMonth(m), BorrowDay(d)*/ {}
	Book(string& bn, string& bid, bool ib/*, int py, string& a,
		int y, int m, int d*/) ;
	virtual void markBorrow(Borrow& b) ;
	virtual void markReturn(Borrow& b) ;
};

