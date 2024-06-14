#include"server.h"

int main(void)
{
	Vector intV(10);
	cout<<endl;
	size_t iCounter;

	cout<<"\n Befor Insert:- ";
	for( iCounter = 0;iCounter < intV.Size();iCounter++)
	{
		intV[iCounter] = iCounter;
		cout<<" "<<intV[iCounter];
	}

	intV.insert(intV.end(),100);

	cout<<"\n After Insert:- ";
	for(Vector::Iterater iter = intV.begin(); iter !=  intV.end();++iter)
	{
		cout<<" "<<*iter;
	}
	
	Vector NewV(20);

	cout<<"\n\n Befor NewV Insert:- ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}

	NewV.insert(NewV.end(),100);

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
	for(Vector::Iterater iter = intV.begin(); iter !=  intV.end();++iter)
	{
		cout<<" "<<*iter;
	}
	NewV.insert(NewV.begin(),200);
	cout<<"\n\nAfter NewV Insert(At begin):-\n ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}
	
	cout<<"\nEnter Position :- ";
	cin>>iCounter;

	NewV.insert(NewV.AtPosition(iCounter),500);

	cout<<"\n\nAfter NewV Insert(At Position):-\n\n ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}
	
	// free the caller obj memory which is allocsted dynamically 
	intV.free();

	cout<<"\n\n Display intV object :- \n\n";
	cout<<intV;

	cin>>iCounter;
	cin.get();
	return 0;
}
