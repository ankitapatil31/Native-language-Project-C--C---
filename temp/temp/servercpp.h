
#include<iostream>
#include"Server_h.h"
using namespace std;

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
	{
		cout<<"Memory Allocation Fail"<<endl;
		return;
	}
	pDummy->pNext = pDummy;
	pDummy->pPrev = pDummy;
}
template <typename T>
List<T>::~List()
{
	cout<<"Destructor in List"<<endl;
	if(pDummy->pNext != pDummy)
	{
		DeleteAllNode();
	}
	pDummy->pNext = pDummy->pPrev = NULL;
	delete(pDummy);
	pDummy = NULL;
}

template<typename T>
void List<T>::InsertLast(T iNo)
{
	Node<T> *pNewNode = new Node<T>();
	if(NULL == pNewNode)
	{
		cout<<"memory allocation fail"<<endl;
		return;
	}
	pNewNode->iData = iNo;
	pDummy->pPrev->pNext = pNewNode;
	pNewNode->pPrev = pDummy->pPrev;
	pNewNode->pNext = pDummy;
	pDummy->pPrev = pNewNode;
	pNewNode = NULL;
	return;
}

template<typename T>
void List<T>::InsertFirst(T iNo)
{
	Node<T> *pNewNode = new Node<T>();
	if(NULL == pNewNode)
	{
		cout<<"memory allocation fail"<<endl;
		return;
	}
	pNewNode->iData = iNo;
	pNewNode->pNext = pDummy->pNext;
	pDummy->pNext->pPrev = pNewNode;
	pNewNode->pPrev = pDummy;
	pDummy->pNext = pNewNode;
	pNewNode = NULL;
	return;
}


template<typename T>
void List<T>::InsertAtPosition(int iPos,T iNo)
{
	int iCount = 1;
	Node<T> *pTemp = pDummy->pNext;
	if(iPos == 1)
	{
		InsertFirst(iNo);
		return;
	}
	if(iPos == CountNode()+1)
	{
		InsertLast(iNo);
		return;
	}
	node<T> *pNewNode = new node<T>(); 
	if(NULL == pNewNode)
	{
		cout<<"Memory Allocation Fail";
		return;
	}
	while(iCount < iPos-1)
	{
		iCount++;
		pTemp = pTemp->pNext;
	}
	pNewNode->iData = iNo;
	pNewNode->pNext = pTemp->pNext;
	pNewNode->pNext->pPrev = pNewNode;
	pNewNode->pPrev = pTemp;
	pTemp->pNext = pNewNode;
	pNewNode = pTemp = NULL;
	return;
}


template<typename T>
T List<T>::DeleteFirst()
{
	T iDelData = 0;
	if(pDummy == pDummy->pNext)
	{
		return iDelData;
	}
	iDelData = pDummy->pNext->iData;
	pDummy->pNext  = pDummy->pNext->pNext;
	pDummy->pNext->pPrev->pNext = NULL;
	pDummy->pNext->pPrev->pPrev = NULL;
	delete(pDummy->pNext->pPrev);
	pDummy->pNext->pPrev = pDummy;

	return iDelData;
}

template<typename T>
T List<T>::DeleteLast()
{
	T iDelData = 0;
	if(pDummy == pDummy->pNext)
	{
		return iDelData;
	}
	iDelData = pDummy->pPrev->iData;
	pDummy->pPrev = pDummy->pPrev->pPrev;
	delete(pDummy->pPrev->pNext);
	pDummy->pPrev->pNext = pDummy;
	
	return iDelData;
}
template <typename T>
T List<T>::DeleteAtPosition(int iPos)
{
	T iDelData = 0;
	int iCount;
	node<T> *pTemp = pDummy->pNext;
	if(pDummy == pDummy->pNext)
	{
		return iDelData;
	}
	if(iPos == 1)
	{
		return DeleteFirst();
	}
	if(iPos == CountNode())
	{
		return DeleteLast();
	}
	iCount = 1;
    while(iCount < iPos)
    {
        iCount++;
        pTemp=pTemp->pNext;
    } 
	iDelData = pTemp->iData;
	pTemp->pPrev->pNext = pTemp->pNext;
	pTemp->pNext->pPrev = pTemp->pPrev;

	pTemp->pNext = pTemp->pPrev = NULL;
	delete(pTemp);

	pTemp = NULL;
	return iDelData;
}


template<typename T>
int List<T>::SearchFirstOccurrence(T iKey)
{
	int iPos=1;
	Node<T> *pTemp = pDummy->pNext;
            
	if(pDummy == pDummy->pNext)
        return iPos;
    while(pTemp != pDummy)
    {
        if(iKey == pTemp->iData)
            return iPos;
		 iPos++;
        pTemp = pTemp->pNext;       
    }
            
    pTemp=NULL;
    return 0;
}
template<typename T>
int List<T>::SearchLastOccurrence(T iKey)
{
	int iPos=1,iCount = 0;
	Node<T> *pTemp = pDummy->pNext;
            
    while(pTemp != pDummy)
    {
         iCount++;
        if(iKey == pTemp->iData)
            iPos=iCount;
        pTemp = pTemp->pNext;    
    }
            
    pTemp=NULL;
    return iPos;
}
template<typename T>
int List<T>::SearchAllOccurrence(T iKey)
{
	int iCount=0;
    Node<T> *pTemp = pDummy->pNext;
            
	if(pDummy == pDummy->pNext)
        return iCount;
    while(pTemp != pDummy)
    {
        if(iKey == pTemp->iData)
            iCount++;
        pTemp = pTemp->pNext;
	 }
            
    pTemp = NULL;
    return iCount;
}
template<typename T>
int List<T>::CountNode()
{
	int iCount = 0;
	Node<T> *pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		iCount++;
		pTemp = pTemp->pNext;
	}
	pTemp = NULL;
	return iCount;
}
template<typename T>
void List<T>:: Display()
{
	Node<T> *pTemp = pDummy->pNext;

	while(pTemp != pDummy)
	{
		cout<<"<-|"<<pTemp->iData<<"|->";
		pTemp = pTemp->pNext;
	}
	pTemp = NULL;
	return;
}
template <typename T>
void List<T>::DeleteAllNode()
{
	Node<T> *pTemp = pDummy->pNext;
	if(pDummy == pDummy->pNext)
		return;

	while(pDummy != pDummy->pNext)
    {       
		pDummy->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pDummy;
		pTemp->pNext = pTemp->pPrev = NULL;

        delete(pTemp);  
		pTemp = pDummy->pNext;
    }
}


template<typename T>
List<T>::Iterater::Iterater()
{
    pCurrent = NULL;
}
template<typename T>
List<T>::Iterater::Iterater(Node<T> *pTemp)
{
	pCurrent = pTemp;
}
template<typename T>
List<T>::Iterater::~Iterater()
{
	pCurrent = NULL;
}
template<typename T>
void List<T>::Iterater::setcurrent(Node<T> *pTemp)
{
    pCurrent = pTemp;
}

template<typename T>
Node<T>* List<T>::Iterater::getcurrent()
{
    return pCurrent;
}
template<typename T>
bool List<T>::Iterater::operator!=(Iterater &refiter)
{
    if(pCurrent != refiter.pCurrent)
        return true;
    return false;    
}
template<typename T>
T List<T>::Iterater::operator *()
{
    return pCurrent->iData;
}
/*
template<typename T>
Iterater&  List<T>::begin()
{
	start_iter.setcurrent(pDummy->pNext);
    return start_iter;       
}
/*template<typename T>
List<T>::Iterater& List:: end()
{
	end_iter.setcurrent(pDummy);
    return end_iter;
}*/