#ifndef Server_h
#define Server_h
#include<iostream>
using namespace std;
template <typename T>
class Node
{
	Node<T> *pPrev;
	T iData;
	Node<T> *pNext;
public:
	Node();
	~Node();
	template <typename T>
	friend class List;
};
template <typename T>
class List
{
	Node<T> *pDummy;
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
	void InsertAtPosition(int,T);
	void DeleteAllNodes();
	
	class Iterater
	{
		Node<T> *pCurrent;
	public:
		Iterater();
		~Iterater();
		Iterater(Node<T>*);
		T operator *();
		Node<T>* getcurrent();
		Iterater& operator ++();
		Iterater& operator --();
		void setcurrent(Node<T> *);
		Iterater operator ++(int);
		Iterater operator --(int);
		bool operator !=(Iterater & refiter);

	};
private:
	Iterater end_iter;
	Iterater start_iter;
public:
	Iterater&  end();
	Iterater& begin();

};
#endif
/*
template <typename T>
Node<T>::Node()
{
	pPrev = NULL;
	iData = 0;
	pNext = NULL;
}
template <typename T>
Node<T>::~Node()
{
	pPrev = NULL;
	pNext = NULL;
}
template <typename T>
List<T>::List()
{
	pDummy = new Node<T>();
	if(NULL == pDummy)
		cout<<"fail";
}
template <typename T>
List<T>::~List()
{
	pDummy = new Node<T>();
	if(NULL == pDummy)
		cout<<"fail";
}
*/