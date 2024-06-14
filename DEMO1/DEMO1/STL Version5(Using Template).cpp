#include<iostream>
using namespace std;
template<typename T>
class node
{
	node<T> * pPrev;
	T iData;
	node<T> * pNext;
public:
	node()
	{
		pPrev = NULL;
		iData = 0;
		pNext = NULL;
	}
	~node()
	{
		if( NULL != pNext )
		{
			pPrev = NULL;
			pNext = NULL;
		}
	}
	template<typename T>
	friend class List;
};
template<typename T>
class List
{
	node<T> *pDummy;
public:
	List()
	{
		pDummy = new node<T>();
		if(NULL == pDummy)
		{
			cout<<"Memory Allocation Fail"<<endl;
			return;
		}
		pDummy->pNext = pDummy;
		pDummy->pPrev = pDummy;
	}
	~List()
	{
		if(NULL != pDummy)
		{
			DeleteAllNode();
		}
	}
	void Display();
	int CountNode();
	T DeleteLast();
	T DeleteFirst();
	void DeleteAllNode();
	void InsertLast(T iNo);
	void InsertFirst(T iNo)
	{
		node<T> *pNewNode = new node<T>();
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
	T DeleteAtPosition(int iNO);
	int SearchAllOccurrence(T iNo);
	int SearchLastOccurrence(T iNo);
	int SearchFirstOccurrence(T iNo);
	void InsertAtPosition(int iPos,T iNo);
	template<typename T>
	class Iterater
	{
		node<T>*pCurrent;
	public:
		Iterater();
		~Iterater();
		Iterater(node<T>* pTemp)
		{
			pCurrent = pTemp;
		}
		T operator *()
		{
			return pCurrent->iData;
		}
		node<T>* getcurrent()
		{
			return pCurrent
		}
		Iterater<T>& operator ++()
		{
			pCurrent = pCurrent->pNext;
			return *this;
		}
		Iterater<T>& operator --();
		void setcurrent(node <T>* pTemp)
		{
			pCurrent = pTemp;
		}
		Iterater<T>& operator ++(int);
		Iterater<T>& operator --(int);
		
		bool operator !=(Iterater<T>& refiter)
		{
			if(pCurrent != refiter.pCurrent)
				return true;
			return false;  
		}
	};
private:
	Iterater<T> end_iter;
	Iterater<T> start_iter;
public:
	Iterater<T>&  end()
	{
		start_iter.setcurrent(pDummy->pNext);
			return start_iter;   
	}
	Iterater<T>& begin()
	{
		end_iter.setcurrent(pDummy);
    return end_iter;
	}
};

template<typename T>
void DisplayIterater(List<T> &l)
{
	cout<<"*******************************"<<endl;
    cout<<"*******Iterater Display********"<<endl;
	cout<<"*******************************\n"<<endl;
	/*if(l.begin() == l.end())
	{
		cout<<"LinkList is Empty"<<endl;
	}*/
    for(List<T>::Iterater<T> iter = l.begin(); iter != l.end(); ++iter)
    {
        cout<<"<-|"<<*iter<<"|->";
    }
	cout<<"\n\n******************************"<<endl;
}
template<typename T>
void mymain(T)
{
    int iCase,iPos;
    T iData;
    List<T> l;
    
    while(1)
    {
        cout<<"\n******* Main Menu *******"<<endl;
        cout<<"\n1 Insert\n2 Delete\n3 Search\n4 Count\n5 Back"<<endl;
        cout<<"\n*************************"<<endl;

        cout<<"\nEnter Your Choice :-\t";
        cin>>iCase;
        switch(iCase)
        {
            case 1:
                    do
                    {
                        cout<<"******* INSERT SUBMEMU *******"<<endl;
                        cout<<"\n1 Insrt Frist\n2 Insert Last\n3 Insert At Possition\n4 Back\n"<<endl;
                        cout<<"******************************"<<endl;
                        cout<<"\nEnter Your Choice:- \t";
                        cin>>iCase;
                        switch(iCase)
                        {
                            case 1: 
                                    cout<<"\nEnter Data :-\n"<<endl;
                                    cin>>iData;
                                    cout<<"--------------"<<endl;
                                    l.InsertFirst(iData);
                                    
                                    DisplayIterater(l);  
                                    break;
                           /* case 2:
                                    cout<<"\nEnter Data :-\n"<<endl;
                                    cin>>iData;
                                    cout<<"--------------"<<endl;
                                    l.InsertLast(iData); 
                                    
                                    l.Display();
             
                                    break;
                            case 3:
                                    cout<<"\nEnter Position \n"<<endl;
                                    cin>>iPos;
                                    cout<<"-------------------"<<endl;
  
                                    iCase=l.CountNode(); 
                                    
                                    if( iPos >= 1 && iPos <= iCase+1 )
                                    {
                                        cout<<"Enter the Date"<<endl;
                                        cin>>iData;
                                        cout<<"----------------"<<endl;
                                        
                                        l.InsertAtPosition(iPos,iData);
                                        l.Display();
                                    }
                                    else
                                    {
                                        cout<<"\n Enter valid Possition\n"<<endl;
                                    }
                                    break;
                            case 4:
                                      
                                    break;*/
                            default:
                                        cout<<"\n\nInvalid Input!!!\n\n";
                                    break;
                        }
                    }while(iCase!=4);
                    break;
       /*      case 2:
                    if(NULL==l.CountNode())
                    {
                        cout<<"\n---LinkedList All Ready Empty---\n"<<endl;
                        break;
                    }
                    do
                    {
                        cout<<"******* DELETE SUBMEMU *******"<<endl;
                        cout<<"\n1 Delete Frist\n2 Delete Last\n3 Delete At Possition\n4 Back"<<endl;
                        cout<<"******************************"<<endl;
                        cout<<"\nEnter Your Choice:-\t";
                        cin>>iCase;
                        switch(iCase)
                        {
                            case 1:
                                    iData=l.DeleteFirst();
                                    if(iData != 0)
                                        cout<<"\n Deleted value is:-"<<iData<<endl;
                                    else
                                        cout<<"\nLinkedList is Empty\n"<<endl;
                                    
                                    l.Display();
                                    break;
                            case 2:
                                     iData = l.DeleteLast();
                                     if(iData != 0)
                                        cout<<"\n Deleted value is:-"<<iData<<endl;
                                    
                                    l.Display();
                                    break;
                            case 3:
                                    
                                    cout<<"\nEnter Position \n"<<endl;
                                    cin>>iPos;
            
                                    iCase=l.CountNode(); 
                                   
                                    if(iPos>=1&&iPos<=iCase+1)
                                    {
                                         iData = l.DeleteAtPosition(iPos);
                                         if(iData != 0)
                                         cout<<"\n Deleted value is:-"<<iData<<endl;
                                         l.Display();
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
                    }while(iCase!=4);
          
                    break;
            case 3:
                   
                    if(NULL == l.CountNode())
                    {
                        printf("\n---LinkedList All Ready Empty---\n\n");
                        break;
                        // continue;
                    }
                    do
                    {   
                        cout<<"\n******* SEARCH SUBMEMU *******\n"<<endl;
                        cout<<"\n1 Search Frist Occourence\n2 Search Last Occourence\n3 Search All Occourence\n4 Back\n"<<endl;
                        cout<<"******************************"<<endl;
                        cout<<"\nEnter Your Choice:-\t ";
                        cin>>iCase;
            
                        switch(iCase)
                        {
                            case 1:
                                    cout<<"\nEnter a Key value for Search :-"<<endl;
                                    cin>>iData;
                                    cout<<"----------------------------------" <<endl; 
                                    
                                    iPos=l.SearchFirstOccurrence(iData);
                                    
                                    if(iPos==0)
                                        cout<<"Key Not Found In LinkedList"<<endl;
                                    else
                                        cout<<" Key value["<<iData<<" Found at Position "<<iPos<<endl;
                           
                                    l.Display();   
                                    break;
                            case 2:
                                    cout<<"\nEnter a Key value for Search :- "<<endl;
                                    cin>>iData;   
                                    cout<<"----------------------------------" <<endl; 

                                    iPos=l.SearchLastOccurrence(iData);
                                    if(iPos==0)
                                        cout<<"Key Not Found In LinkedList"<<endl;
                                    else
                                        cout<<" Key value["<<iData<<"] Found at Position  "<<iPos<<endl;
                                                   
                                    l.Display();
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
                                                   
                                    l.Display();
                                    break;
                            case 4:
                                 
                                    break;
                            default:
                                    cout<<"\n\nInvalid Input!!!\n\n";
                                    break;
                        }
                    }while(iCase!=4);
           
                   break;
            case 4:
   
                    iCase=l.CountNode();
                    cout<<"\n**********************************"<<endl;
                    cout<<"\nTotal Count Of LinkList :-"<<iCase<<"\n\n";
                    cout<<"**********************************\n"<<endl;
                    break;
            case 5:  
                    if(NULL != l.CountNode()) 
                        l.DeleteAllNode();
                    return;
           */
            default:
                    cout<<"\n\nInvalid Input!!!\n\n";
                    break;
        }
    }
}

int main()
{
    char iCase;
    
    while(1)
    {
        cout<<"\n**********************************"<<endl;
        cout<<"Which type of linkedlist you want"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"\n1 Interger \n2 Charecter \n3 Float \n4 Double \n5 Exit\n";
        cout<<"\nEnter Your Choice :- \t";
        cin>>iCase;
    
        switch(iCase)
        {
            case '1': 
                    mymain(10);
                    break;
            case '2':
                    mymain('A');
                    break;
            case '3':
                    mymain(10.56f);
                    break;
            case '4':
                    mymain(50.445);
                    break;
            case '5' : exit(0);
        
            default:
                    cout<<"Invalid Input"<<endl;
                    break;
        } 
   }
   return 0;
} 
      
    
    

  