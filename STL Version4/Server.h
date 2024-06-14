class node
{
	private:
		node *pPrev;
		int iData;
		node *pNext;
	public:
		node();
		~node();
	friend class List;
};
class List
{
	public:
		class Iterater
        {
            node *pCurrent;
            public:
                Iterater()
                {
                    pCurrent = NULL;
                }
                Iterater(node *pTemp)
                {
					pCurrent = pTemp;
                }
                void setcurrent(node *pTemp)
                {
                    pCurrent = pTemp;
                }
                node * getcurrent()
                {
                    return pCurrent;
                }
                Iterater& operator ++()
                {
                    pCurrent = pCurrent->pNext;
                    return *this;
                }
				Iterater operator ++(int)
                {
					Iterater pTemp(pCurrent);
                    pCurrent = pCurrent->pNext;
                    return pTemp;
                }
                bool operator!=(List::Iterater &refiter)
                {
                    if(pCurrent != refiter.pCurrent)
                        return true;
                    return false;    
                }
				bool operator>=(List::Iterater &refiter)
                {
					if(pCurrent->iData >= refiter.pCurrent->iData)
                        return true;
                    return false;
                }
				bool operator<=(List::Iterater &refiter)
                {
					if(pCurrent->iData <= refiter.pCurrent->iData)
                        return true;
                    return false;
                }
				bool operator>(List::Iterater &refiter)
                {
					if(pCurrent->iData > refiter.pCurrent->iData)
                        return true;
                    return false;
                }
				bool operator<(List::Iterater &refiter)
                {
					if(pCurrent->iData < refiter.pCurrent->iData)
                        return true;
                    return false;
                }
                int operator *()
                {
                    return pCurrent->iData;
                }
             
        };
	private:
		node *pFirst;
		node *pLast;
		Iterater start_iterater;
		Iterater end_iterater;
	public:
		List();
		~List();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPosition(int,int);
		int DeleteFirst();
		int DeleteLast();
		int DeleteAtPosition(int);
		int SearchFirstOccurrence(int);
		int SearchLastOccurrence(int);
		int SearchAllOccurrence(int);
		int CountNode();
		void Display();
		void DeleteAllNode();
        Iterater&  begin();
        Iterater&  end();
};
