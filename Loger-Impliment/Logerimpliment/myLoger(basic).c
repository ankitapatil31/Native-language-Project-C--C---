/*
#include<stdio.h>
#include<conio.h>
#include "myloger_headerfile.h"

void fun1();
void fun2();
void fun3();

int main()
{
	#if logmain
		printf("In main fun\n");
	#endif

    #if logmain
		printf("fun1 call\n");
	#endif

	fun1();

	#if logmain
		printf("leaving main fun\n");
	#endif
	_getch();
    return 0;
}
void fun1()
{
 
	#if logfun1
		printf("in fun1\n");
    #endif

    #if logfun2
		printf("fun2 call\n");
    #endif

    fun2();

    #if logfun1
		printf("leaving fun1\n");
    #endif
}
void fun2()
{
	#if logfun2
		printf("in fun2\n");
    #endif

    #if logfun3
		printf("fun3 call\n");
    #endif

   fun3();

    #if logfun2
		printf("leaving fun2\n");
    #endif
}  
void fun3()
{
	#if logfun3
		printf("in fun3\n");
        printf("leaving fun3\n");
    #endif
}
*/