#include<iostream>
#include"Server_h.h"
#include"servercpp.h"
using namespace std;

template <typename T>
void DisplatIterater(List<T> &l)
{
	List<T>::Iterater iter;
	/*for(List<T>::Iterater iter = l.begin(); iter != l.end(); ++iter)
    {
        cout<<"<-|"<<*iter<<"|->";
    }*/
}

template <typename T>
void myMain(T)
{
	List<T> l;
	T iData;
	cout<<"Enter Data"<<endl;
	cin>>iData;
	cin.get();
	l.InsertFirst(iData);
	l.Display();
	cin.get();
}
int main()
{
	myMain(10);
}