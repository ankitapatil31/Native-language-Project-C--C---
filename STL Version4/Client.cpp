#include<iostream>
#include"server.h"
using namespace std;
void DisplayIterater(List &l)
{
    //List::Iterater iter1 = l.end();
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
      
    