#include "server.h"

#pragma once
size_t Vector::size()
{
	return m_iSize;
}

ostream & operator <<(ostream& out,Vector& v)
{
	int pTemp = 0;
	for(pTemp = 0; pTemp != v.m_iSize; pTemp++)
	{
		out << "v.m_pPtr[pTemp]" <<' ';
	}
	return out;
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

	//iTemp = 0;
	//pTemp = NULL;
}

 void Vector::Insert(Iterator& obj, int iData)
{
	int *pTemp = NULL;
	m_iSize++;
	size_t iRet = 0;
	pTemp = new int[m_iSize];
	if(NULL == pTemp)
	{
		cout << "Memory allocation failed";
		return;
	}
	cout<<"\n in insert";
/*
	//if client want to add data at end
	//iRet = obj.GetCurrentIndex();
	cout<<"iret"<<iRet<<"msize"<<m_iSize;
	/*if(iRet == m_iSize-1)
	{
		memcpy(pTemp, m_pPtr, 0, m_iSize-1);
		pTemp[m_iSize-1] = iData;	
	}

	//if client want to add data at 1st position
	/*if(iRet == 0)
	{
		pTemp[0] = iData;
		memcpy(pTemp+1, m_pPtr, 0, m_iSize);
	}

	//deleting old array
	m_pPtr = pTemp;
	delete[] pTemp;
	pTemp = NULL;*/
 }
