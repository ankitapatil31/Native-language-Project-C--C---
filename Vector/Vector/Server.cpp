#include"server.h"
ostream& operator <<(ostream &out,Vector &refobj)
{
	if(NULL == refobj.pPtr)
	{
		out<<"All Ready Empty"<<endl;
		return out;
	}
	for(Vector::Iterater iter = refobj.begin(); iter !=  refobj.end();++iter)
	{
		cout<<" "<<*iter;
	}
	return out;
}
Vector::Iterater::Iterater():m_iIndex(0),pIndex(NULL){}

Vector::Iterater::Iterater(size_t iSize, int * pTempIndex)
{
	m_iIndex = iSize;
	pIndex = pTempIndex;
}
Vector::Iterater::~Iterater()
{
	m_iIndex = 0;
	pIndex = NULL;
}
void Vector::Iterater::SetCurrentIndex(size_t iSize, int * pTempIndex)
{
	m_iIndex = iSize;
	pIndex = pTempIndex;
}
size_t Vector::Iterater::GetCurrentIndex()
{
	return m_iIndex;
}
int * Vector::Iterater::GetCurrentAddress()
{
	return pIndex;
}
Vector::Iterater& Vector::Iterater::operator ++()
{
	pIndex = pIndex+1;
	m_iIndex++;
	return *this;
}
bool Vector::Iterater::operator !=(Iterater &refobj)
{
	if(m_iIndex != refobj.m_iIndex)
		return true;
	return false;
}
bool Vector::Iterater::operator <=(Iterater &refobj)
{
	if(m_iIndex <= refobj.m_iIndex)
		return true;
	return false;
}
int Vector::Iterater::operator *()
{
	return *pIndex;
}

// Vector 

Vector::Vector():pPtr(NULL),m_iSize(){}

Vector::Vector(int iSize)
{
	m_iSize = iSize;
	pPtr = new int[m_iSize];
	if(NULL == pPtr)
	{
		cout<<"Memory Allocation Fail \n";
		return;
	}
	memset(pPtr, 0, m_iSize*sizeof(pPtr));
}
Vector::~Vector()
{
	if(NULL != pPtr)
	{
		delete []pPtr;
		pPtr = NULL;
		m_iSize = 0;
	}
}
size_t Vector::Size()
{
	return m_iSize;
}
void Vector::free()
{
	if(NULL != pPtr)
	{
		delete []pPtr;
		pPtr = NULL;
		m_iSize = 0;
	}
	return;
}

int& Vector::operator [](size_t iData)
{
	if(iData > m_iSize)
	{
		cout<<"Array Index out of bound";
		return pPtr[iData];
	}
	return pPtr[iData];
}
void Vector::swap(Vector &refobj)
{
	size_t iTemp;
	int *pTemp = NULL;

	iTemp =	m_iSize;
	pTemp = pPtr;

	pPtr = refobj.pPtr;
	refobj.pPtr = pTemp;
	pTemp = NULL;

	m_iSize = refobj.m_iSize;
	refobj.m_iSize = iTemp;
}

void Vector::insert(Iterater &iter,int iValue)
{
	int * pTemp = NULL;
	size_t iCounter = iter.GetCurrentIndex();

	if(iCounter < 0 && iCounter >= m_iSize+1)
		return;
	m_iSize++;
	pTemp = new int[m_iSize];								//navin memory banavli
	if(NULL == pTemp)
	{
		cout<<"Memory allocation Fail"<<endl;
		return;
	}
	if(iCounter == m_iSize-1)
	{	
		mymemcpy(pTemp,pPtr,0,m_iSize-1);				//adhich memory madhala data copy kela navin memory madhe
	}
	else if(iCounter == 0)
	{
		mymemcpy(pTemp+1,pPtr,0 ,m_iSize-1);						//adhich memory madhala data copy kela navin memory madhe
	}
	else if(iCounter >=1 && iCounter <= m_iSize)
	{
		mymemcpy(pTemp,pPtr,0,iCounter);						//adhich memory madhala data copy kela navin memory madhe
		pTemp[iCounter-1] = iValue;	
		mymemcpy(pTemp+1,pPtr,iCounter-1,m_iSize);
	}
	delete[] pPtr;												//Adhi chi memory free keli 10 byte chi...
	pPtr = NULL;

	pPtr = pTemp;												// navin 11 byte chi memory(tyach address) pPtr madhe set set kela...
	pTemp = NULL; 												//etha mi maja realloc define kela ahe
	if(iCounter == m_iSize-1 || iCounter == 0)
		pPtr[iCounter] = iValue;

	return;
}
Vector::Iterater&  Vector::AtPosition(int iPos)
{
	if(iPos >= 0 && iPos <= m_iSize+1)
	{
		atpos_iter.SetCurrentIndex(iPos,pPtr);
	}
	else
	{
		cout<<"\n Invalid Position!!!!!!";
	}
	return atpos_iter;
}
Vector::Iterater&  Vector::begin()
{
	start_iter.SetCurrentIndex(0,pPtr);
	return start_iter;
}

Vector::Iterater&  Vector::end()
{
	end_iter.SetCurrentIndex(m_iSize,&pPtr[m_iSize-1]);
	return end_iter;
}
/*
void * Vector::realloc(void * iPtr,size_t iSize)
{
	int * pTemp = NULL;

	pTemp = new int[iSize];										//navin memory banavli
	if(NULL == pTemp)
	{
		cout<<"Memory allocation Fail"<<endl;
		return NULL;
	}
	mymemcpy(pTemp,(int *)iPtr,0,iSize-1);						//adhich memory madhala data copy kela navin memory madhe
		
	delete[] iPtr;												//Adhi chi memory free keli 10 byte chi...
	iPtr = NULL;

	pPtr = pTemp;												// navin 11 byte chi memory(tyach address) pPtr madhe set set kela...
	pTemp = NULL; 
	return pPtr;
}*/

