#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Vector
{
	T *m_pPtr;
	size_t m_iSize;
	void Vector:: mymemcpy(T * destination, T * source,size_t First_Index,size_t Last_Index)
	{
		size_t i;
		if(NULL == source)
				return;
		for(i = First_Index;i < Last_Index;i++)
		{
			destination[i] = source[i];
		}

	}
public:
	Vector():m_pPtr(NULL),m_iSize(0){}
	Vector(size_t iSize)
	{
		m_iSize = iSize;
		m_pPtr = new T[m_iSize];
		if(NULL == m_pPtr)
		{
			cout<<"Memory Allocation Fail \n";
			return;
		}
		memset(m_pPtr,'0', m_iSize*sizeof(T));
		
	}
	~Vector()
	{
		if(NULL != m_pPtr)
		{
			delete []m_pPtr;
			m_pPtr = NULL;
			m_iSize = 0;
		}
	}
	class Iterater
	{
		size_t m_iIndex;
		T * pIndex;
	public:
		Iterater():m_iIndex(0),pIndex(NULL){}
		Iterater(size_t iSize, T * pTempIndex)
		{
			m_iIndex = iSize;
			pIndex = pTempIndex;
		}
		~Iterater()
		{
			m_iIndex = 0;
			pIndex = NULL;
		}
		T operator *()
		{
			return *pIndex;
		}
		Iterater& operator ++()
		{
			pIndex = pIndex+1;
			m_iIndex++;
			return *this;
		}
		int GetCurrentIndex()
		{
			return m_iIndex;
		}
		T * GetCurrentAddress()
		{
			return pIndex;
		}
		bool operator !=(Iterater & refobj)
		{
			if(m_iIndex != refobj.m_iIndex)
				return true;
			return false;
		}
		bool operator <=(Iterater & refobj)
		{
			if(m_iIndex <= refobj.m_iIndex)
				return true;
			return false;
		}
		void SetCurrentIndex(size_t iSize ,  T * pTempIndex )
		{
			m_iIndex = iSize;
			pIndex = pTempIndex;
		}

	};
	size_t Size()
	{
		return m_iSize;
	}  
	void free()
	{
		if(NULL != m_pPtr)
		{
			delete []m_pPtr;
			m_pPtr = NULL;
			m_iSize = 0;
		}
		return;
	}
	
	T& Vector::operator [](size_t iData)
	{
		if(iData > m_iSize)
		{
			cout<<"Array Index out of bound";
			return m_pPtr[iData];
		}
		return m_pPtr[iData];
	}
	void Vector::swap(Vector<T> &refobj)
	{
		size_t iTemp;
		T *pTemp = NULL;

		iTemp =	m_iSize;
		pTemp = m_pPtr;

		m_pPtr = refobj.m_pPtr;
		refobj.m_pPtr = pTemp;
		pTemp = NULL;

		m_iSize = refobj.m_iSize;
		refobj.m_iSize = iTemp;
	}
	void Vector::insert(Iterater &iter,T iValue)
	{
		T * pTemp = NULL;
		size_t iCounter = iter.GetCurrentIndex();

		if(iCounter < 0 && iCounter >= m_iSize+1)
			return;
		m_iSize++;
		pTemp = new T[m_iSize];								//navin memory banavli
		if(NULL == pTemp)
		{
			cout<<"Memory allocation Fail"<<endl;
			return;
		}
		if(iCounter == m_iSize-1)
		{	
			mymemcpy(pTemp,m_pPtr,0,m_iSize-1);				//adhich memory madhala data copy kela navin memory madhe
		}
		else if(iCounter == 0)
		{
			mymemcpy(pTemp+1,m_pPtr,0 ,m_iSize-1);						//adhich memory madhala data copy kela navin memory madhe
		}
		else if(iCounter >=1 && iCounter <= m_iSize)
		{
			mymemcpy(pTemp,m_pPtr,0,iCounter);						//adhich memory madhala data copy kela navin memory madhe
			pTemp[iCounter-1] = iValue;	
			mymemcpy(pTemp+1,m_pPtr,iCounter-1,m_iSize);
		}

		delete[] m_pPtr;												//Adhi chi memory free keli 10 byte chi...
		m_pPtr = NULL;

		m_pPtr = pTemp;												// navin 11 byte chi memory(tyach address) pPtr madhe set set kela...
		pTemp = NULL; 												//etha mi maja realloc define kela ahe
		if(iCounter == m_iSize-1 || iCounter == 0)
			m_pPtr[iCounter] = iValue;

		return;
	}

	private:
		Iterater start_iter;
		Iterater end_iter;
		Iterater atpos_iter;
	public:
		Iterater&  AtPosition(size_t iPos)
		{
			if(iPos >= 0 && iPos <= m_iSize+1)
			{
				atpos_iter.SetCurrentIndex(iPos,m_pPtr);
			}
			else
				cout<<"\n Invalid Position!!!!!!";
			return atpos_iter;
		}
		Iterater&  begin()
		{
			start_iter.SetCurrentIndex(0,m_pPtr);
			return start_iter;
		}

		Iterater&  end()
		{
			end_iter.SetCurrentIndex(m_iSize,&m_pPtr[m_iSize-1]);
			return end_iter;
		}
	
};
