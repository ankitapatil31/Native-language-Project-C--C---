/*#include<iostream>
using namespace std;
class node
{
	private:
		node *pPrev;
		int iData;
		node *pNext;
	public:
		node();
		~node();
	friend class List;
};
class List
{
	public:
		class Iterater
        {
            node *pCurrent;
            public:
                Iterater()
                {
                    pCurrent = NULL;
                }
                Iterater(node *pTemp)
                {
					pCurrent = pTemp;
                }
                void setcurrent(node *pTemp)
                {
                    pCurrent = pTemp;
                }
                node * getcurrent()
                {
                    return pCurrent;
                }
                Iterater& operator ++()
                {
                    pCurrent = pCurrent->pNext;
                    return *this;
                }
				Iterater operator ++(int)
                {
					Iterater pTemp(pCurrent);
                    pCurrent = pCurrent->pNext;
                    return pTemp;
                }
				Iterater& operator --()
                {
                    pCurrent = pCurrent->pPrev;
                    return *this;
                }
				Iterater operator --(int)
                {
					Iterater pTemp(pCurrent);
                    pCurrent = pCurrent->pPrev;
                    return pTemp;
                }
                bool operator!=(List::Iterater &refiter)
                {
                    if(pCurrent != refiter.pCurrent)
                        return true;
                    return false;    
                }
				bool operator>=(List::Iterater &refiter)
                {
					if(pCurrent->iData >= refiter.pCurrent->iData)
                        return true;
                    return false;
                }
				bool operator<=(List::Iterater &refiter)
                {
					if(pCurrent->iData <= refiter.pCurrent->iData)
                        return true;
                    return false;
                }
				bool operator>(List::Iterater &refiter)
                {
					if(pCurrent->iData > refiter.pCurrent->iData)
                        return true;
                    return false;
                }
				bool operator<(List::Iterater &refiter)
                {
					if(pCurrent->iData < refiter.pCurrent->iData)
                        return true;
                    return false;
                }
                int operator *()
                {
                    return pCurrent->iData;
                }
             
        };
	private:
		node *pFirst;
		node *pLast;
		Iterater start_iterater;
		Iterater end_iterater;
	public:
		List();
		~List();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPosition(int,int);
		int DeleteFirst();
		int DeleteLast();
		int DeleteAtPosition(int);
		int SearchFirstOccurrence(int);
		int SearchLastOccurrence(int);
		int SearchAllOccurrence(int);
		int CountNode();
		void Display();
		void DeleteAllNode();
        Iterater&  begin();
        Iterater&  end();
};
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
    //printf("pFirst %d",pFirst);
    pTemp=NULL;
    cout<<"\n\n******************************\n"<<endl;
}    
void DisplayIterater(List &l)
{
    cout<<"Iterater Display"<<endl;
    for(List::Iterater iter = l.begin(); iter != l.end(); ++iter)
    {
        cout<<"<-|"<<*iter<<"|->";
    }
}
int main()
{
    int iData,iPos;
    List l;
    cout<<"\n******* MenuDriven *******\n"<<endl;
    while(1)
    {
        cout<<"******* Main Menu *******"<<endl;
        cout<<"\n1 Insert\n2 Delete\n3 Search\n4 Count\n5 Exit"<<endl;
        cout<<"*************************"<<endl;

        cout<<"\nEnter Your Choice "<<endl;
        cin>>iData;
        switch(iData)
        {
            case 1:
                    do
                    {
                        cout<<"******* INSERT SUBMEMU *******"<<endl;
                        cout<<"\n1 Insrt Frist\n2 Insert Last\n3 Insert At Possition\n4 Back\n"<<endl;
                        cout<<"******************************"<<endl;
                        cout<<"\nEnter Your Choice "<<endl;
                        cin>>iData;
                        switch(iData)
                        {
                            case 1: 
                                    cout<<"\nEnter Data :-\n"<<endl;
                                    cin>>iData;
                                    cout<<"--------------"<<endl;
                                    l.InsertFirst(iData);
                                    DisplayIterater(l);
                                    //l.Display();  
                                    break;
                            case 2:
                                    cout<<"\nEnter Data :-\n"<<endl;
                                    cin>>iData;
                                    cout<<"--------------"<<endl;
                                    l.InsertLast(iData); 
                                    
                                    DisplayIterater(l);
             
                                    break;
                            case 3:
                                    cout<<"\nEnter Position \n"<<endl;
                                    cin>>iPos;
                                    cout<<"-------------------"<<endl;
  
                                    iData=l.CountNode(); 
                                    
                                    if( iPos >= 1 && iPos <= iData+1 )
                                    {
                                        cout<<"Enter the Date"<<endl;
                                        cin>>iData;
                                        cout<<"----------------"<<endl;
                                        
                                        l.InsertAtPosition(iPos,iData);
                                        DisplayIterater(l);
                                    }
                                    else
                                    {
                                        cout<<"\n Enter valid Possition\n"<<endl;
                                    }
                                    break;
                            case 4:
                                      
                                    break;
                            default:
                                        cout<<"\n\nInvalid Input!!!\n\n";
                                    break;
                        }
                    }while(iData!=4);
                    break;
            case 2:
                    if(NULL==l.CountNode())
                    {
                        cout<<"\n---LinkedList All Ready Empty---\n"<<endl;
                        continue;
                    }
                    do
                    {
                        cout<<"******* DELETE SUBMEMU *******"<<endl;
                        cout<<"\n1 Delete Frist\n2 Delete Last\n3 Delete At Possition\n4 Back"<<endl;
                        cout<<"******************************"<<endl;
                        cout<<"\nEnter Your Choice "<<endl;
                        cin>>iData;
                        switch(iData)
                        {
                            case 1:
                                    iData=l.DeleteFirst();
                                    if(iData != 0)
                                        cout<<"\n Deleted value is:-"<<iData<<endl;
                                    else
                                        cout<<"\nLinkedList is Empty\n"<<endl;
                                    
                                    DisplayIterater(l);
                                    break;
                            case 2:
                                     iData = l.DeleteLast();
                                     if(iData != 0)
                                        cout<<"\n Deleted value is:-"<<iData<<endl;
                                    
                                    DisplayIterater(l);
                                    break;
                            case 3:
                                    
                                    cout<<"\nEnter Position \n"<<endl;
                                    cin>>iPos;
            
                                    iData=l.CountNode(); 
                                   
                                    if(iPos>=1&&iPos<=iData+1)
                                    {
                                         iData = l.DeleteAtPosition(iPos);
                                         if(iData != 0)
                                         cout<<"\n Deleted value is:-"<<iData<<endl;
                                         DisplayIterater(l);
                                    }
                                    else
                                    {
                                        printf("Enter valid Possition");
                                    }
                                    break;
                            case 4:
                                
                                    break;
                            default:
                                    cout<<"\n\nInvalid Input!!!\n\n";
                                    break;
                        }
                    }while(iData!=4);
          
                    break;
            case 3:
                   
                    if(NULL == l.CountNode())
                    {
                        printf("\n---LinkedList All Ready Empty---\n\n");
                        continue;
                    }
                    do
                    {   
                        cout<<"\n******* SEARCH SUBMEMU *******\n"<<endl;
                        cout<<"\n1 Search Frist Occourence\n2 Search Last Occourence\n3 Search All Occourence\n4 Back\n"<<endl;
                        cout<<"******************************"<<endl;
                        cout<<"\nEnter Your Choice "<<endl;
                        cin>>iData;
            
                        switch(iData)
                        {
                            case 1:
                                    cout<<"\nEnter a Key value for Search :-"<<endl;
                                    cin>>iData;
                                    cout<<"----------------------------------" <<endl; 
                                    
                                    iPos=l.SearchFirstOccurrence(iData);
                                    
                                    if(iPos==0)
                                        cout<<"Key Not Found In LinkedList"<<endl;
                                    else
                                        cout<<" Key value["<<iData<<"] in LinkedList at Position "<<iPos<<endl;
                           
                                    DisplayIterater(l); 
                                    break;
                            case 2:
                                    cout<<"\nEnter a Key value for Search :- "<<endl;
                                    cin>>iData;   
                                    cout<<"----------------------------------" <<endl; 

                                    iPos=l.SearchLastOccurrence(iData);
                                    if(iPos==0)
                                        cout<<"Key Not Found In LinkedList"<<endl;
                                    else
                                        cout<<" Key value["<<iData<<"] in LinkedList at Position  "<<iPos<<endl;
                                                   
                                    DisplayIterater(l);
                                    break;
                            case 3:
                                    cout<<"\nEnter a Key value for Search :- "<<endl;
                                    cin>>iData;   
                                    cout<<"----------------------------------" <<endl; 

                                    iPos=l.SearchAllOccurrence(iData);
                                    if(iPos==0)
                                        cout<<"Key Not Found In LinkedList"<<endl;
                                    else
                                        cout<<" Key value["<<iData<<"] Found in LinkedList, "<<iPos<<" Times"<<endl;
                                                   
                                    DisplayIterater(l);
                                    break;
                            case 4:
                                 
                                    break;
                            default:
                                    cout<<"\n\nInvalid Input!!!\n\n";
                                    break;
                        }
                    }while(iData!=4);
           
                   break;
            case 4:
   
                    iData=l.CountNode();
                    cout<<"\n**********************************"<<endl;
                    cout<<"\nTotal Count Of LinkList :-"<<iData<<"\n\n";
                    cout<<"**********************************\n"<<endl;
                    break;
            case 5:  
					cout<<"Exit";
                    if(NULL != l.CountNode())
                        l.DeleteAllNode();
                    return 0;
           
            default:
                    cout<<"\n\nInvalid Input!!!\n\n";
                    break;
        }
     
    }
}    
      
*/