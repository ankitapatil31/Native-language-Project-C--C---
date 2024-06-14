/*#include<iostream>
using namespace std;
class demo
{
    static int iCounter;
	static int iCount;
public:
	demo()
	{

		
		iCount++;
		iCounter++;
	}
	demo(demo & obj)
	{
		iCount++;
		iCounter++;
	}
	~demo()
	{
		iCount--;
	}
	void Display()
	{
		cout<<"\n\nTotal Object"<<iCounter;
		cout<<"\nCurrently obj"<<iCount;
	}
	void fun()
	{
		demo obj1,obj2,obj3;
		Display();
	}
	static void fun2()
	{
		cout<<"Access private member :-"<<iCount<<" "<<iCounter;
	}
};


int demo::iCounter = 0;
int demo::iCount = 0;

int main()
{
	demo obj,obj2;
	obj.Display();
	obj.fun();
	obj.Display();

	demo::fun2();
	cin.get();
	return 0;
}
*/