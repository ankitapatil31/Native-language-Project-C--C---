
#pragma once
#include<iostream>
using namespace std;

class Vector
{
	int *m_pPtr;
	size_t m_iSize;

	void memcpy(int *pDest, int *pSource, size_t StartIndex, size_t EndIndex)
	 {
		 for(size_t iCounter = StartIndex; iCounter < EndIndex; iCounter++)
		 {
			 pDest[iCounter] = pSource[iCounter];
			 cout<<"memcpy"<<pDest[iCounter]<<endl;
		 }
	 }

public:
	Vector()
	{
		m_pPtr = NULL;
		m_iSize = 0;
	}

	Vector(size_t iSize)
	{
		m_iSize = iSize;
		m_pPtr = new int[iSize];
		if(NULL == m_pPtr)
		{
			cout << "Memory allocation Failed";
			return;
		}

		//for ZeroOut array
		memset(m_pPtr, 0, m_iSize);
	}

	~Vector()
	{
		if(m_pPtr != NULL)
		{
			delete []m_pPtr;
			m_pPtr = NULL;
		}
	}
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
		Iterator()
		{
			m_iIndex = 0;
			m_pIndex = NULL;
		}

		Iterator & SetCurrentElement(size_t iNewIndex, int *pNewIndex)
		{
			m_iIndex = iNewIndex;
			m_pIndex = pNewIndex;
			return *this;
		}

		size_t GetCurrentIndex()
		{
			return m_iIndex;
		}

		int *GetCurrentAddress()
		{
			return m_pIndex;
		}

		//pre increment operator overloading
		Iterator& operator ++()
		{
			m_pIndex++;
			m_iIndex++;
			return *this;
		}

		Iterator operator ++(int)
		{
			Iterator obj;
			obj = *this;
			m_pIndex++;
			m_iIndex++;
			return obj;
		}

		bool operator !=(Vector::Iterator& refobj)
		{
			 if(m_iIndex != refobj.m_iIndex)
				 return true;

			 return false;
		}

		int operator *()
		{
			return *m_pIndex;
		}
		
		/*bool operator <(Iterator& refobj)
		{
			if(m_iIndex < refobj.m_iIndex)
				return true;

			return false;
		}

		bool operator =(Iterator& refobj)
		{
			if(m_iIndex = refobj.m_iIndex)
				return true;

			return false;
		}*/

		//friend class Vector;
	};//Class iterator close

	
	//Member function of Vector
	 void Insert(Iterator& obj, int iData);
	 size_t size();
	 void Swap(Vector& pPtr);                                                                                                                                      

	 //Data members of Vector
	Iterator StartIter;
	Iterator EndIter;

	Iterator& Begin()
	{
		StartIter.SetCurrentElement(0, m_pPtr);	
		return StartIter;
	}

	Iterator& End()
	{
		EndIter.SetCurrentElement(m_iSize, &(m_pPtr[m_iSize-1]));
		return EndIter;
	}
};

