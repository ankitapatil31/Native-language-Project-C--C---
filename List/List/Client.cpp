#include"Server.h"
#include<iterator>
#include<algorithm>
#include<iostream>
using namespace std;
void printfList(List &l1,List &l2)
{
	cout<<"\nList1:-";
	for(List::Iterater iter = l1.begin();iter!= l1.end();++iter)
	{
		cout<<" "<<*iter;
	}
	cout<<"\nList2:-";
	for(List::Iterater iter = l2.begin();iter!= l2.end();++iter)
	{
		cout<<" "<<*iter;
	}

}
void printfList(List &l1)
{
	cout<<"\nList1:-";
	for(List::Iterater iter = l1.begin();iter!= l1.end();++iter)
	{
		cout<<" "<<*iter;
	}
}
int main()
{
	List l1,l2;
	for(int i = 0;i<6;i++)
	{
		l1.push_back(i+65);
		l2.push_front(i+65);
	}
	l2.push_front(98);
	l2.push_front(3);
	printfList(l1,l2);
	
	cout<<"\n\n Sort The List:- ";
	l1.Sort();
	printfList(l1,l2);

	cout<<"\n\n splicing :-\n";
	find(l2.begin(),l2.end(),98);

	/*
		l1.splice(l2.end(),l2,l2.begin());
		printfList(l1,l2);

		cout<<"\n Sort ListL;-";
		l2.sort();
		printfList(l1,l2);

		cout<<"\n after list2 assing to list1:-";
		l1 = l2;
		l2.push_front(2+65);
		printfList(l1,l2);

		cout<<"\n  list2 unique:-";
		l2.unique();
		printfList(l1,l2);

		cout<<"\nAfter marge";
	l1.mearge(l2);
	printfList(l1,l2);
	
	*/

	cin.get();
	return 0;
}