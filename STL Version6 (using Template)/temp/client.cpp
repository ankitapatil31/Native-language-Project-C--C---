#include<iostream>
#include"Server_h.h"
using namespace std;

template <typename T>
void DisplayIterater(List<T> &l);

template <typename T>
void mymain(T);

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
}
template <typename T>
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
                                    
                                    cout<<l;
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
  
                                    iCase=l.CountNode(); 
                                    
                                    if( iPos >= 1 && iPos <= iCase+1 )
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
                    }while(iCase!=4);
                    break;
             case 2:
                    if(NULL==l.CountNode())
                    {
                        cout<<"\n---LinkedList All Ready Empty---\n"<<endl;
                        break;
                    }
                    do
                    {
						if(NULL==l.CountNode())
							break;
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
									 {
                                        cout<<"\n Deleted value is:-"<<iData<<endl;
										if(NULL != l.CountNode())
											DisplayIterater(l);
									 }
									 else
                                        cout<<"\n---LinkedList All Ready Empty---\n"<<endl;

                                    break;
                            case 2:
                                     iData = l.DeleteLast();
                                     if(iData != 0)
									 {
                                        cout<<"\n Deleted value is:-"<<iData<<endl;
										if(NULL != l.CountNode())
											DisplayIterater(l);
									 }
									 else
                                       cout<<"\n---LinkedList All Ready Empty---\n"<<endl;
                                    break;
                            case 3:
                                    
                                    cout<<"\nEnter Position \n"<<endl;
                                    cin>>iPos;
            
                                    iCase=l.CountNode(); 
                                   
                                   if(iPos>=1&&iPos<=iData)
                                    {
										iData = l.DeleteAtPosition(iPos);
                                        if(iData != 0)
										{
											cout<<"\n Deleted value is:-"<<iData<<endl;
											if(NULL != l.CountNode())
												DisplayIterater(l);
										}
										else
											cout<<"\n---LinkedList All Ready Empty---\n"<<endl;
                                    }
                                    else
                                        cout<<"\nEnter valid Possition\n";
                                    
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
                        cout<<"\n---LinkedList All Ready Empty---\n\n";
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
                                        cout<<" Key value["<<iData<<"] Found at Position  "<<iPos<<endl;
                                                   
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
           
            default:
                    cout<<"\n\nInvalid Input!!!\n\n";
                    break;
        }
    }
	cin.get();
}

template <typename T>
void DisplayIterater(List<T> &l)
{
	cout<<"*******************************"<<endl;
    cout<<"*******Iterater Display********"<<endl;
	cout<<"*******************************\n"<<endl;
    for(List<T>::Iterater iter = l.begin(); iter != l.end(); ++iter)
    {
        cout<<"<-|"<<*iter<<"|->";
    }
	cout<<"\n\n******************************"<<endl;
}
