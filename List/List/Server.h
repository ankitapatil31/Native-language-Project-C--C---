/*
#ifndef Server_h
#define Server_h*/
#include<iostream>
using namespace std;
class Iterater;
class node
{
	node * pPrev;
	int iData;
	node * pNext;
public:
	node();
	~node();
	friend class List;
	friend ostream& operator << (ostream & out, List &refobj);
	friend	Iterater& find(Iterater &refobjstart,Iterater &refobjend, int iData);


};
class List
{
	node * pDummy;
public:
	List();
	~List();
	void Display();
	int CountNode();
	int DeleteLast();
	int DeleteFirst();
	void DeleteAllNode();
	void InsertLast(int);
	void InsertFirst(int);
	int DeleteAtPosition(int);
	int SearchAllOccurrence(int);
	int SearchLastOccurrence(int);
	int SearchFirstOccurrence(int);
	void InsertAtPosition(int,int);
	class Iterater
	{
		node *pCurrent;
	public:
		Iterater();
		~Iterater();
		Iterater(node*);
		int operator *();
		node* getcurrent();
		Iterater& operator ++();
		Iterater& operator --();
		void setcurrent(node *);
		int getvalue(node * pTemp)
		{
			return pTemp->iData;
		}
		Iterater operator ++(int);
		Iterater operator --(int);
		bool operator>(List::Iterater &);
		bool operator<(List::Iterater &);
		bool operator>=(List::Iterater &);
		bool operator<=(List::Iterater &);
		bool operator==(List::Iterater &);
		bool operator !=(List::Iterater & refiter);
		friend	Iterater& find(Iterater &refobjstart,Iterater &refobjend, int iData);

	};
private:
	Iterater end_iter;
	Iterater start_iter;
public:
	Iterater&  end();
	Iterater& begin();
	void Sort();
	void push_back(int);
	void push_front(int);
	void mearge(List &l);
	friend ostream& operator << (ostream & out, List &refobj);
	void splice(Iterater &refobj,List & list1);
};
//#endif