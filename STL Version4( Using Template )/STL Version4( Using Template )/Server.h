
#ifndef Server_h
#define Server_h
#include<iostream>
using namespace std;
template<typename T>
class node
{
	node<T> * pPrev;
	T iData;
	node<T> * pNext;
public:
	node();
	~node();
	template<typename T>
	friend class List;
};
template<typename T>
class List
{
	node<T> * pDummy;
public:
	List();
	~List();
	void Display();
	int CountNode();
	T DeleteLast();
	T DeleteFirst();
	void DeleteAllNode();
	void InsertLast(T);
	void InsertFirst(T);
	T DeleteAtPosition(int);
	int SearchAllOccurrence(T);
	int SearchLastOccurrence(T);
	int SearchFirstOccurrence(T);	
	void InsertAtPosition(int iPos,T iNo);

};
#endif
