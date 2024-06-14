#include<iostream>
using namespace std;

#ifndef __VECTOR_H
#define __VECTOR_H

class Vector
{
	size_t m_iSize;
	int *m_pPtr;
	void memcpy(int *pDest, int *pSource, size_t StartIndex, size_t EndIndex);

public:
	Vector();
	Vector(size_t);
	~Vector();
	size_t size();

	friend ostream & operator <<(ostream & out, Vector & v);

	//operator [] overloading
	int &operator [](int n)
	{
		return m_pPtr[n];
	}

	class Iterator
	{
		size_t m_iIndex;
		int *m_pIndex;

	public:
		Iterator();
		Iterator & SetCurrentElement(size_t iNewIndex, int *pNewIndex);
		size_t GetCurrentIndex();
		int *GetCurrentAddress();

		//pre increment operator overloading
		Iterator& operator ++();
		Iterator operator ++(int);
		int operator *();
		bool operator !=(Vector::Iterator& refobj);
	};                                                                                                                                     

	//Data members of Vector
	Iterator StartIter;
	Iterator EndIter;

	//Member functions of Vector
	void Insert(Iterator& obj, int iData);
	void Swap(Vector& pPtr); 

	Iterator& Begin();
	Iterator& End();
};

#endif