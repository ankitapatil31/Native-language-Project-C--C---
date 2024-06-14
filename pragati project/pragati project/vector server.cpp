#include "Vector.h"

void Vector::memcpy(int *pDest, int *pSource, size_t StartIndex, size_t EndIndex)
{
	for(size_t iCounter = StartIndex; iCounter < EndIndex; iCounter++)
	{
		pDest[iCounter] = pSource[iCounter];
		
	}
}

Vector::Vector()
{
	m_iSize = 0;
	m_pPtr = NULL;
}

Vector::Vector(size_t iSize)
{
	m_iSize = iSize;
	m_pPtr = new int[m_iSize];

	if(m_pPtr == NULL)
	{
		cout << "Memory allocation failed";
		return;
	}

	//for ZeroOut array
	memset(m_pPtr, 0, m_iSize*sizeof(m_pPtr));
}


Vector::~Vector()
{
	if(m_pPtr != NULL)
	{
		delete[] m_pPtr;
		m_pPtr = NULL;
	}
}

size_t Vector::size()
{
	return m_iSize;
}

ostream & operator <<(ostream& out,Vector& v)
{
	int pTemp = 0;
	for(pTemp = 0; pTemp != v.m_iSize; pTemp++)
	{
		out << v.m_pPtr[pTemp] <<' ';
	}
	return out;
}

Vector::Iterator::Iterator()
{
	m_iIndex = 0;
	m_pIndex = NULL;
}

Vector::Iterator& Vector::Iterator:: SetCurrentElement(size_t iNewIndex, int *pNewIndex)
{
	m_iIndex = iNewIndex;
	m_pIndex = pNewIndex;
	return *this;
}

size_t Vector::Iterator::GetCurrentIndex()
{
	return m_iIndex;
}

int* Vector::Iterator:: GetCurrentAddress()
{
	return m_pIndex;
}

Vector::Iterator& Vector::Iterator::operator ++()
{
	m_pIndex++;
	m_iIndex++;
	return *this;
}

Vector::Iterator Vector::Iterator::operator ++(int)
{
	Iterator obj;
	obj = *this;
	m_pIndex++;
	m_iIndex++;
	return obj;
}

int Vector::Iterator::operator *()
{
	return *m_pIndex;
}

bool Vector::Iterator::operator !=(Vector::Iterator& refobj)
{
	if(m_iIndex != refobj.m_iIndex)
		return true;

	return false;
}

Vector::Iterator& Vector::Begin()
{
	StartIter.SetCurrentElement(0, m_pPtr);	
	return StartIter;
}

Vector::Iterator& Vector::End()
{
	EndIter.SetCurrentElement(m_iSize, &(m_pPtr[m_iSize-1]));
	return EndIter;
}

void Vector::Swap(Vector& pPtr)                                                                                                                                       
{
	size_t iTemp;
	int *pTemp;

	//cout<<"hhh";
	iTemp = pPtr.m_iSize;
	pTemp = pPtr.m_pPtr;

	pPtr.m_iSize = this->m_iSize;
	pPtr.m_pPtr = this->m_pPtr;

	this->m_iSize = iTemp;
	this->m_pPtr = pTemp;

	iTemp = 0;
	pTemp = NULL;
}

void Vector::Insert(Iterator& obj, int iData)
{
	int *pTemp = NULL;
	size_t iRet;
	m_iSize++;

	pTemp = new int[m_iSize];
	if(NULL == pTemp)
	{
		cout << "Memory allocation failed";
		return;
	}

	//if client want to add data at end
	iRet = obj.GetCurrentIndex();
	cout<<"Index"<< iRet <<"size"<<m_iSize;

	
	
	memcpy(pTemp, m_pPtr, 0, m_iSize-1);
	pTemp[m_iSize-1] = iData;
		


	

	///*if(iRet == 0)
	//{
	//	pTemp[0] = iData;
	//	memcpy(pTemp+1, m_pPtr, 0, m_iSize-1);
	//}*/
	//m_pPtr = pTemp;

	//deleting old array
	delete[] m_pPtr;
	m_pPtr = pTemp;
	pTemp = NULL;
}