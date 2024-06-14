//
//#include<iostream>
//using namespace std;
//class CBase
//{
//public:
//	CBase()
//	{
//		cout<<"\n In Base Constructor";
//		//fun();
//		/*
//			virtual pan ahe upcasting pan ahe and redefination pan ahe so vatta ki inhance
//			function bhetel pan constructor madhun to tyacha ch function la call karto karan 
//			to jevha call hoto teva tyach vptr madhe tyach vTable ch address asto mhnun to
//			tyach ch tunction call krto
//		*/
//	}
//	virtual void fun()
//	{
//		cout<<"\n In Base fun";
//	}
//	void fun1()
//	{
//		fun();
//	}
//	~CBase()
//	{
//		cout<<"befor";
//		fun();
//		/*
//			destructor calling sequence nusar derived ch kam jal ki base ch destroctor la 
//			yeto teva tr tyach derived ch obj madhalya vptr madhe derived ch vptr inialize
//			pn jalela asto so vatta to vptr derived ch vtable bagun derived ch cvall karel
//			pan deructor ahe to tyach sampaun ala ahe ge complier la mahiti ahe mhnun to
//			base ch function call karel 
//		*/
//		cout<<"\n In Base Destructor";
//	}
//
//};
//class CDerived:public CBase
//{
//public:
//	CDerived()
//	{
//		cout<<"\n In Derived Constructor";
//	}
//	~CDerived()
//	{
//		cout<<"\n In Derived Destructor";
//	}
//	void fun()
//	{
//		cout<<"\n In Derived fun";
//	}
//};
//int main()
//{
//	CDerived dobj;
//	CBase *bp = NULL;
//	bp = &dobj;
//	cout<<"\n\n\ fun1 call";
//	bp->fun1();
//	cin.get();
//	return 0;
//}
///*
//	khar tr to vptr and vtable bagat ch nhi ya case madhe to eary binding 
//	krto etha compile time ch call instructon la address bind kela jato.
//
//*/