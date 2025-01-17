#include<iostream>
using namespace std;
class Vector
{
	int *pPtr;
	size_t m_iSize;
public:
	Vector():pPtr(NULL),m_iSize(0){}

	Vector(int iSize)
	{
		m_iSize = iSize;
		pPtr = new int[m_iSize];
		if(NULL == pPtr)
		{
			cout<<"Memory Allocation Fail \n";
			return;
		}
		memset(pPtr, 0, m_iSize*sizeof(pPtr));

		/*for(int i = 0;i< 5;i++)
		{
			pPtr[i] = i;
			cout<<"\n value of :-  "<<pPtr[i];
		}*/
	}
	~Vector()
	{
		cout<<"\nDestructor"<<endl;
	}
	class Iterater
	{
		size_t m_iIndex;
		int * pIndex;
	public:
		Iterater():m_iIndex(0),pIndex(NULL){}

		Iterater(size_t iSize, int * pTempIndex)
		{
			m_iIndex = iSize;
			pIndex = pTempIndex;
		}
		~Iterater()
		{
			cout<<"In Iterator Destructor";
		}
		void SetCurrentIndex(size_t iSize, int * pTempIndex)
		{
			m_iIndex = iSize;
			pIndex = pTempIndex;
		}
		size_t GetCurrentIndex()
		{
			return m_iIndex;
		}
		int * GetCurrentAddress()
		{
			return pIndex;
		}
		Iterater& operator ++()
		{
			pIndex = pIndex+1;
			m_iIndex++;
			return *this;
		}
		bool operator !=(Iterater &refobj)
		{
			if(m_iIndex != refobj.m_iIndex)
				return true;
			return false;
		}
		int operator *()
		{
			return *pIndex;
		}

	};
	int& operator[](size_t iData)
	{
		if(iData > m_iSize)
		{
			cout<<"Array Index out of bound";
			return pPtr[iData];
		}
		return pPtr[iData];
	}
	
	void mymemcpy(int * destination, int * source,size_t iData)
	{
		if(NULL == source)
			return;
		for(size_t i = 0;i<iData;i++)
			destination[i] = source[i];
	}
	void insert(Iterater &iter,int iValue)
	{
		
		cout<<"\n In Insert";
		size_t iCounter = iter.GetCurrentIndex();
		m_iSize++;
		pPtr = (int *)realloc(pPtr,m_iSize);						//etha mi maja realloc define kela ahe

		pPtr[iCounter] = iValue;
		for(iCounter = 0; iCounter < m_iSize-1; iCounter++);
		
	}
	int * Last()
	{
		/*size_t iCounter;
		m_iSize++;
		pPtr = (int *)realloc(pPtr,m_iSize);						//etha mi maja realloc define kela ahe

		for(iCounter = 0; iCounter < m_iSize-1; iCounter++);
		return &pPtr[iCounter];*/
	}
	size_t Size()
	{
		return m_iSize;
	}

	void * realloc(void * iPtr,size_t iSize)
	{
		int * pTemp = NULL;

		pTemp = new int[iSize];										//navin memory banavli
		if(NULL == pTemp)
		{
			cout<<"Memory allocation Fail"<<endl;
			return NULL;
		}
		mymemcpy(pTemp,(int *)iPtr,m_iSize-1);						//adhich memory madhala data copy kela navin memory madhe
		
		delete[] iPtr;												//Adhi chi memory free keli 10 byte chi...
		iPtr = NULL;

		pPtr = pTemp;												// navin 11 byte chi memory(tyach address) pPtr madhe set set kela...
		pTemp = NULL; 
		return pPtr;
	}
	void swap(Vector &refobj)
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
	
	private:
		Iterater start_iter;
		Iterater end_iter;
	public:
		Iterater&  begin()
		{
			start_iter.SetCurrentIndex(0,pPtr);
			return start_iter;
		}
		Iterater&  end()
		{
			end_iter.SetCurrentIndex(m_iSize,&pPtr[m_iSize-1]);
			return end_iter;
		}
};
int main()
{ 
	Vector intV(10);
	cout<<endl;
	size_t iCounter;

	cout<<"\n Befor Insert:- ";
	for( iCounter = 0;iCounter < intV.Size();iCounter++)
	{
		intV[iCounter] = iCounter;
		cout<<intV[iCounter]<<" ";
	}

	intV.insert(intV.end(),100);

	cout<<"\n After Insert:- ";
	cout<<"\n Iterator Display() :- ";
	for(Vector::Iterater iter = intV.begin(); iter !=  intV.end();++iter)
	{
		cout<<"\t"<<*iter;
	}
	

	Vector NewV(20);

	cout<<"\n\n NewV:- ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}

	NewV.insert(NewV.end(),100);

	cout<<"\n\n NewV:- ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}

	cout<<"\n Swapping of Two Vector :-"<<endl;
	intV.swap(NewV);

	cout<<"\n\n NewV:- ";
	for( iCounter = 0;iCounter < NewV.Size();iCounter++)
	{
		cout<<NewV[iCounter]<<" ";
	}

	cout<<"\n IntV :- ";
	for( iCounter = 0;iCounter < intV.Size();iCounter++)
	{
		cout<<intV[iCounter]<<" ";
	}

	cout<<"\n Iterator Display() :- ";
	for(Vector::Iterater iter = intV.begin(); iter !=  intV.end();++iter)
	{
		cout<<"\t"<<*iter;
	}
	cin.get();
	return 0;
}