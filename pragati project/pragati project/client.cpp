#include "Vector.h"

int main()
{
	Vector intv(10);

	intv.size();
	cout<<"Befor insert :- ";
	for(size_t i = 0; i < intv.size(); ++i)
	{
		intv[i] = i;	//fill vector, random access
		cout << intv[i] <<' ';
	}
	//vector increases on demand
	
	intv.Insert(intv.End(),100);
	//append the number 100 use as array
	cout<<"After insert :- ";
	for(size_t i = 0; i < intv.size(); ++i)
		cout << intv[i] <<' ';
	
	cout << endl << endl;

	////use with an iterator
	for(Vector::Iterator I = intv.Begin(); I != intv.End(); ++I)
	{
		cout<< *I << ' ';
	}

	//cout << endl << endl;

	//Vector newv(20); // all are zero

	//cout << "newv = ";

	//for(size_t i = 0; i < newv.size(); ++i)
	//	cout << newv[i] <<' ';

	////swapping two vectors
	//newv.Swap(intv);

	//cout << "\nnewv after swapping = ";
	//for(size_t i = 0; i < newv.size(); ++i)
	//	cout << newv[i] << ' ';  //old content of newv

	//cout << "\nintv after swapping = ";
	//for(size_t i = 0; i < intv.size(); ++i)
	//	cout << intv[i] << ' ';  //old content of intv

	//cout << "\n\nintv = ";
	//cout << intv;
	//cout << "\n\nnewv = ";
	//cout << newv;

	//cout << endl;
	cin.get();
	return 0;
}