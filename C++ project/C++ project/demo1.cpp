#include<iostream>
using namespace std;
class runable
{
public:
	virtual void run()=0;
};
class thread 
{
public:
	thread(runable &refobj)
	{
		refobj.run();
	}
};
class demo:public runable
{
public:
	void run()
	{
		cout<<"In Derived Run";
	}
};
int main()
{
	demo d;

	thread t(d);
	cin.get();
	return 0;
}