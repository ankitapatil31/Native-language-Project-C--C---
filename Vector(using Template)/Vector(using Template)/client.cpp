#include"server.h"
template <typename T>
void DisplayIterater(Vector<T> &refobj);
int main()
{
	Vector<char> intV(10);
	Vector<char> NewV(5);
	cout<<endl;
	size_t iCounter;

	cout<<"\n Befor Insert:- ";
	for( iCounter = 0;iCounter < intV.Size();iCounter++)
	{
		cout<<" "<<intV[iCounter];
	}

	intV.insert(intV.end(),'c');

	cout<<"\n After Insert:- ";
	for( iCounter = 0;iCounter < intV.Size();iCounter++)
	{
		cout<<" "<<intV[iCounter];
	}
	
	cout<<"\n\n Befor NewV Insert:- ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}

	NewV.insert(NewV.end(),'H');

	cout<<"\n\n After NewV Insert:- ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}

	cout<<"\n\n Swapping of Two Vector :-"<<endl;
	intV.swap(NewV);

	cout<<"\n NewV:- ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}

	cout<<"\n IntV :- ";
	for( iCounter = 0;iCounter < intV.Size();iCounter++)
	{
		cout<<intV[iCounter]<<" ";
	}
	cout<<"\n\n Display Iterator for intV object :- \n\n";
	DisplayIterater(intV);
	NewV.insert(NewV.begin(),'V');
	cout<<"\n\nAfter NewV Insert(At begin):-\n ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}
	
	NewV.insert(NewV.AtPosition(3),'A');

	cout<<"\n\nAfter NewV Insert(At Position):-\n\n ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}
	
	cin.get();
	return 0;
}
template <typename T>
void DisplayIterater(Vector<T> &intV)
{
	for(Vector<T>::Iterater iter = intV.begin(); iter !=  intV.end(); ++iter)
	{
		cout<<" "<<*iter;
	}
}