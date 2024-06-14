
#include<iostream>
using namespace std;
class Vector
{
	int *pPtr;
	size_t m_iSize;
	void * realloc(void * ,size_t);
	template <typename T>
	void mymemcpy(T *, T * ,size_t,size_t);
public:
	class Iterater
	{
		size_t m_iIndex;
		int * pIndex;
	public:
		Iterater();
		~Iterater();
		int operator *();
		Iterater(size_t, int *);
		Iterater& operator ++();
		size_t GetCurrentIndex();
		int * GetCurrentAddress();
		bool operator !=(Iterater &);
		bool operator <=(Iterater &);
		void SetCurrentIndex(size_t , int * );

	};

	Vector();
	~Vector();
	void free();
	size_t Size();
	Vector(int Size);
	void swap(Vector &);
	int& operator[](size_t);
	void insert(Iterater &, int );
	friend void Deallocate(int *);
	private:
		Iterater start_iter;
		Iterater end_iter;
		Iterater atpos_iter;
	public:
		Iterater&	end(); 
		Iterater&	begin();
		Iterater&	AtPosition(int);
		friend ostream& operator <<(ostream &out,Vector &refobj);
		
};
template <typename T>
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