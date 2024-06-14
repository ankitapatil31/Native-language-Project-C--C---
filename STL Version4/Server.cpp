#include<iostream>
#include"server.h"
using namespace std;

node::node()
{
    pPrev=NULL;
    iData = 0;
    pNext=NULL;
}
node::~node()
{
            //printf("Destructor In Node\n");
    if(pNext!=NULL)
    {
        pNext=NULL;
        pPrev=NULL;
    }
}

List::List()
{
    pFirst=NULL;
    pLast=NULL;
}
List::~List()
{
    if(pFirst != NULL)
    {
        DeleteAllNode();
        cout<<"\n---All Node Get Free---\n"<<endl;
    }
}
List::Iterater&  List::begin()
{
    start_iterater.setcurrent(pFirst);
    return start_iterater;       
}
List::Iterater& List:: end()
{
    end_iterater.setcurrent(pLast);
    return end_iterater;
}
void List::DeleteAllNode()
{
	if(NULL == pFirst)
		return;
    while(pFirst!=pLast)
    {
             
            pFirst->pNext->pPrev = pLast;
            pLast->pNext = pFirst->pNext;
            pFirst->pNext = NULL;
            pFirst->pPrev = NULL;
                       
            delete(pFirst);
            pFirst = pLast->pNext;
            
        }
    pFirst->pNext = NULL;
    pFirst->pPrev = NULL;
                        
    delete(pFirst);
    pFirst = NULL;
    pLast = NULL;
           
}
      
void List::InsertFirst(int iNo)
{
    node *pNewNode=new node();
    if(NULL==pNewNode)
    {
        cout<<"Memory allocation Fail"<<endl;
        return;
    }
    pNewNode->iData=iNo;
           
    if(NULL==pFirst)
    {
        pFirst=pNewNode;
        pLast=pNewNode;
    }
    else
    {
        pFirst->pPrev=pNewNode;
        pNewNode->pNext=pFirst;
        pFirst=pNewNode;
    }
    pNewNode->pPrev=pLast;
    pLast->pNext=pNewNode;
    pNewNode = NULL;
    //cout<<"\npFirst data"<<pFirst->iData;
}
void List::InsertLast(int iNo)
{
    node *pNewNode=new node();
    if(NULL==pNewNode)
    {
        cout<<"Memory allocation Fail"<<endl;
        return;
    }
    pNewNode->iData=iNo;
    // cout<<"new node data"<<pNewNode->iData;
    if(NULL==pLast)
    {
        pFirst=pNewNode;
        pLast=pNewNode;
    }
    else
    {
        pLast->pNext=pNewNode;
        pNewNode->pPrev=pLast;
        pLast=pNewNode;
    }
    pNewNode->pNext=pFirst;
    pFirst->pPrev=pNewNode;
    pNewNode=NULL;
        //cout<<"\npFirst data"<<pFirst->iData;
}
void List::InsertAtPosition(int iPos,int iNo)
{
    int iCount=CountNode();
    node *pTemp=pFirst;
    node *pNewNode=NULL;
    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    if(iPos==iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {    
        iCount=1;
        pNewNode=new node();
        if(NULL==pNewNode)
        {
            cout<<"\nMemory Allocation Fail\n";              
            return;
        }
        pNewNode->iData=iNo;
        while(iCount<iPos-1)
        {
            iCount++;
            pTemp=pTemp->pNext;
        }  
        pNewNode->pNext=pTemp->pNext;
        pTemp->pNext->pPrev=pNewNode;
        pTemp->pNext=pNewNode;
        pNewNode->pPrev=pTemp;  
        pNewNode=NULL;
    }
}
int List::DeleteFirst()
{
    int iDel;
    if(NULL==pFirst)
        return -1;
            
    iDel=pFirst->iData;
    if(pFirst==pLast)
    {
        pFirst->pPrev=NULL;
        pFirst->pNext=NULL;
        delete(pFirst);
        pFirst=pLast=NULL;
        return iDel;
    }
    else
    {
        pLast->pNext=pFirst->pNext;
        pFirst->pNext=pLast;
        pFirst->pNext=NULL;
        pFirst->pPrev=NULL;
        delete(pFirst);
        pFirst=pLast->pNext;
        return iDel;
    }
}
int List::DeleteLast()
{
    int iDel;
    if(NULL==pFirst)
        return -1;
            
    iDel=pLast->iData;
    if(pFirst==pLast)
    {
        pLast->pPrev=NULL;
        pLast->pNext=NULL;
        delete(pLast);
        pFirst=pLast=NULL;
        return iDel;
    }
    else
    {
        pLast->pPrev->pNext=pFirst;
        pFirst->pPrev=pLast->pPrev;
        pLast->pNext=NULL;
        pLast->pPrev=NULL;
               
        delete(pLast);
        pLast=pFirst->pPrev;
            
        return iDel;
    }
}
int List::DeleteAtPosition(int iPos)
{
    int iData;
    node *pTemp=pFirst;
    int iCount=CountNode();
            
    if(iPos == 1)
    {
        return DeleteFirst();
    }
    if(iPos == iCount+1)
    {
        return DeleteLast();
    }
    else
    {    
        iCount = 1;
        while(iCount<iPos)
        {
            iCount++;
            pTemp=pTemp->pNext;
        }  
        pTemp->pPrev->pNext=pTemp->pNext;
        pTemp->pNext->pPrev=pTemp->pPrev;
        pTemp->pNext=NULL;
        pTemp->pPrev=NULL;
        iData=pTemp->iData;
        delete(pTemp);
        pTemp=NULL;
        return iData;
    }
}
int List::SearchFirstOccurrence(int iKey)
{
    int iPos=0;
    node *pTemp = pFirst;
            
    if(NULL == pFirst)
        return iPos;
    do
    {
        iPos++;
        if(iKey == pTemp->iData)
            return iPos;
        pTemp = pTemp->pNext;       
    }while(pTemp != pFirst);
            
    pTemp=NULL;
    return 0;
} 
int List::SearchLastOccurrence(int iKey)
{
    int iPos=0,iCount=0;
    node *pTemp = pFirst;
            
    if(NULL == pFirst)
        return iPos;
    do
    {
        iCount++;
        if(iKey == pTemp->iData)
            iPos=iCount;
        pTemp = pTemp->pNext;       
    }while(pTemp != pFirst);
           
    pTemp = NULL;
    return iPos;
}
int List::SearchAllOccurrence(int iKey)
{
    int iCount=0;
    node *pTemp = pFirst;
            
    if(NULL == pFirst)
        return iCount;
    do
    {
        if(iKey == pTemp->iData)
            iCount++;
        pTemp = pTemp->pNext;
    }while(pTemp != pFirst);
            
    pTemp = NULL;
    return iCount;
}
int List::CountNode()
{   
    int iCount = 0;
    node *pTemp = pFirst;
            
    if(NULL == pFirst)
        return iCount;
            
    do
    {
        iCount++;
        pTemp = pTemp->pNext;
            
    }while(pTemp != pFirst);
           
        pTemp=NULL;
    return iCount;
}
void List::Display()
{
    node *pTemp = pFirst;
    cout<<"\n******************************\n";
    cout<<"\n------:Display Linked List :------\n\n";
    if(NULL == pFirst)
    {
        cout<<"\n--Linked List is Empty--\n";
        return;
    }
    do
    {
        cout<<"<-|"<< pTemp->iData <<"|->";
        pTemp = pTemp->pNext;
            
    }while(pTemp != pFirst);
    pTemp=NULL;
    cout<<"\n\n******************************\n"<<endl;
}    