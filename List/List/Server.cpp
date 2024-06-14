#pragma once
#include<iostream>
#include"Server.h"

using namespace std;
std::ostream& operator << (std::ostream & out, List &refobj)
{

	if(refobj.pDummy->pNext == refobj.pDummy)
	{
		printf("%d %d",refobj.pDummy->pNext, refobj.pDummy);
		out<<"Linked List Empty";
		return out;
	}
	for(List::Iterater iter = refobj.begin(); iter != refobj.end(); ++iter)
    {
        out<<"<-|"<<*iter<<"|->";
    }
	out<<endl;
	
	return out;
}
List::Iterater& find(List::Iterater &refobjstart, List::Iterater &refobjend, int iData)
{
		node *pEnd = refobjend.getcurrent();

		while(refobjstart.getcurrent() != pEnd)
		{
			int i = refobjstart.getvalue(refobjstart.getcurrent());
			if( i == iData)
			{
				cout<<"Value Find \n";
				return refobjstart;
			}
			++refobjstart;
		}	
		return refobjstart;
}
node::node()
{
	pPrev = NULL;
	iData = 0;
	pNext = NULL;
}
node::~node()
{
	if( NULL != pNext )
	{
		pPrev = NULL;
		pNext = NULL;
	}
}
List::List()
{
	pDummy = new node();
	if(NULL == pDummy)
	{
		cout<<"Memory Allocation Fail"<<endl;
		return;
	}
	pDummy->pNext = pDummy;
	pDummy->pPrev = pDummy;
}
List::~List()
{
	cout<<"Destructor in List"<<endl;
	if(pDummy->pNext != pDummy)
	{
		DeleteAllNode();
	}
	pDummy->pNext = pDummy->pPrev = NULL;
	delete pDummy;
	pDummy = NULL;
}
List::Iterater::Iterater()
{
    pCurrent = NULL;
}
List::Iterater::Iterater(node *pTemp)
{
	pCurrent = pTemp;
}
List::Iterater::~Iterater()
{
	pCurrent = NULL;
}
void List::Iterater::setcurrent(node *pTemp)
{
    pCurrent = pTemp;
}
node * List::Iterater::getcurrent()
{
    return pCurrent;
}

List::Iterater& List::Iterater::operator ++()
{
    pCurrent = pCurrent->pNext;
    return *this;
}
List::Iterater  List::Iterater:: operator ++(int)
{
	Iterater pTemp(pCurrent);
    pCurrent = pCurrent->pNext;
    return pTemp;
}
 List::Iterater&  List::Iterater:: operator --()
{
    pCurrent = pCurrent->pPrev;
    return *this;
}
 List::Iterater  List::Iterater::operator --(int)
{
	Iterater pTemp(pCurrent);
    pCurrent = pCurrent->pPrev;
    return pTemp;
}
bool List::Iterater::operator!=(List::Iterater &refiter)
{
    if(pCurrent != refiter.pCurrent)
        return true;
    return false;    
}
bool  List::Iterater::operator>=(List::Iterater &refiter)
{
	if(pCurrent->iData >= refiter.pCurrent->iData)
        return true;
    return false;
}
bool List::Iterater::operator<=(List::Iterater &refiter)
{
	if(pCurrent->iData <= refiter.pCurrent->iData)
        return true;
    return false;
}
bool List::Iterater::operator==(List::Iterater &refiter)
{
	if(pCurrent == refiter.pCurrent)
        return true;
    return false;
}
bool List::Iterater::operator>(List::Iterater &refiter)
{
	if(pCurrent->iData > refiter.pCurrent->iData)
        return true;
    return false;
}
bool List::Iterater::operator<(List::Iterater &refiter)
{
	if(pCurrent->iData < refiter.pCurrent->iData)
        return true;
    return false;
}
 int List::Iterater::operator *()
{
    return pCurrent->iData;
}

List::Iterater&  List::begin()
{
	start_iter.setcurrent(pDummy->pNext);
    return start_iter;       
}
List::Iterater& List:: end()
{
	end_iter.setcurrent(pDummy);
    return end_iter;
}
void List::InsertFirst(int iNo)
{
	node *pNewNode = new node();
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
void List::InsertLast(int iNo)
{
	node *pNewNode = new node();
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
void List::InsertAtPosition(int iPos,int iNo)
{
	int iCount = 1;
	node *pTemp = NULL;
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

	pTemp = pDummy->pNext;
	node *pNewNode = new node(); 
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
int List::DeleteFirst()
{
	int iDelData = 0;
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
int List::DeleteLast()
{
	int iDelData = 0;
	if(pDummy == pDummy->pNext)
	{
		return iDelData;
	}
	iDelData = pDummy->pPrev->iData;
	pDummy->pPrev = pDummy->pPrev->pPrev;
	pDummy->pPrev->pNext->pNext = NULL;
	pDummy->pPrev->pNext->pPrev = NULL;
	delete(pDummy->pPrev->pNext);
	pDummy->pPrev->pNext = pDummy;
	
	return iDelData;
}
int List::DeleteAtPosition(int iPos)
{
	int iDelData = 0,iCount;
	node *pTemp = NULL;
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
	pTemp = pDummy->pNext;
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
int List::SearchFirstOccurrence(int iKey)
{
	int iPos=1;
	node *pTemp = pDummy->pNext;
            
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
int List::SearchLastOccurrence(int iKey)
{
	int iPos=0,iCount = 0;
	node *pTemp = pDummy->pNext;
    
	if(pDummy == pDummy->pNext)
        return iPos;       
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
int List::SearchAllOccurrence(int iKey)
{
	int iCount=0;
    node *pTemp = pDummy->pNext;
            
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
int List::CountNode()
{
	int iCount = 0;
	node *pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		iCount++;
		pTemp = pTemp->pNext;
	}
	pTemp = NULL;
	return iCount;
}
void List:: Display()
{
	node *pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		cout<<"<-|"<<pTemp->iData<<"|->";
		pTemp = pTemp->pNext;
	}
	pTemp = NULL;
	return;
}
void List::DeleteAllNode()
{
	node *pTemp = pDummy->pNext;
	if(pDummy == pDummy->pNext)
		return;

	while(pDummy != pDummy->pNext)
    {    
		cout<<"hii";
		cout<<pDummy->iData;
		/*pDummy->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pDummy;
		pTemp->pNext = pTemp->pPrev = NULL;

        delete pTemp;  
		pTemp = pDummy->pNext;*/
		break;
    }
}
void List::push_back(int iData)
{
	InsertLast(iData);
}
void List::push_front(int iData)
{
	InsertFirst(iData);
}
void List::Sort()
{
	int iCount;
	cout<<"pdummy :- "<<pDummy <<"   "<<pDummy->pNext;
	if(pDummy == pDummy->pNext)
	{
		cout<<"Emmpty";
		return;
	}
	node*pCurrent = NULL,*pNext = NULL;
	cout<<"\n In Sort";
	for(pCurrent = pDummy->pNext;pCurrent->pNext != pDummy;pCurrent= pCurrent->pNext)
	{
		for( pNext = pCurrent->pNext;pNext != pDummy;pNext= pNext->pNext)
		{
			cout<<"\n hii";
			if(pCurrent->iData < pNext->iData)
			{
				/*iCount = pCurrent->iData;
				pCurrent->iData = pNext->iData;
				pNext->iData = iCount;*/
				
				pNext->pNext->pPrev = pCurrent;
				pCurrent->pNext = pNext->pNext;
				pNext->pNext = pCurrent;
				pCurrent->pPrev = pNext;
			}
		}
		
	}
	
}
void List::mearge(List &l)
{
	cout<<"marge";
	/*Display();
	l.Display();*/

	cout<<"\nPdummy"<<pDummy;
	cout<<"\nPdummy"<<pDummy->pPrev->pNext;
	
	pDummy->pPrev->pNext = l.pDummy->pNext;
	l.pDummy->pNext->pPrev = pDummy->pPrev;
	pDummy->pPrev = l.pDummy->pPrev;
	l.pDummy->pPrev->pNext = pDummy;

	l.pDummy->pPrev = l.pDummy->pNext = l.pDummy;

	Display();
	
}
/*
Iterater& find(Iterater &refobjstart,Iterater &refobjend, int iData);
{
	int iPos=0,iCount = 1;
	node*pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		if(pTemp->iData == iData)
		{
			printf("idata %d \n ",pTemp->iData);
			printf("pTemp %d",pTemp);
			printf("\n %d\n\n", start_iter.getcurrent());
			break;
		}
		printf("| pTemp %d \t idata %d |",pTemp,pTemp->iData);
		pTemp = pTemp->pNext;
	}
	return refobjstart;
}*/

void List::splice(Iterater &refobj,List & list1)
{
	
}