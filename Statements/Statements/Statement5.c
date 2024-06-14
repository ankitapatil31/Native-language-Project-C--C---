
#include<stdio.h>
#include<conio.h>
void fun3();
void fun4(); 
void fun1(void(*(*)[2])());
void fun2(void(*(*)[2])());
int main()
{
	void (*ary[2])();
	void (*arr[3])(void(*(*)[2])());
	void (*(*p))(void(*(*)[2])()) = NULL;
	
	ary[0] = fun3;
	ary[1] = fun4;
	
	p = arr;
	p[0] = fun1;
	p[1] = fun2;

	p[0](&ary);
	p[1](&ary);

	getch();
	return 0;
}
void fun3()
{
	printf("\nIn Fun3");
}
void fun4()
{
	printf("\nIn Fun4");
}
void fun1(void(*(*ptr)[2])())
{
	printf("\nIn Fun1");
	(*ptr)[0]();
}
void fun2(void(*(*ptr)[2])())
{
	printf("\nIn Fun2");
	(*ptr)[0]();
}