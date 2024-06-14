//#include<stdio.h>
//#include<stdarg.h>
//int myprintf(const char *,...);
//int main()
//{
//	int iret;
//	iret = myprintf("hello \0");
//	myprintf("\t return value is %d\n",iret);
//
//	iret = myprintf("%d \n",10);
//	myprintf("\n return value is %d \n ",iret);
//
//	iret = myprintf("%d %d", 20,30);
//	myprintf("\n return value is %d",iret);
//	
//	iret = sum(3,10,30,20);
//	myprintf("\n\n\n sum of value is %d",iret);
//
//	getch();
//	return 0;
//}
//int myprintf(const char * pszstr,...)
//{
//	int iret;
//	//
//	// va_list is char *
//	//
//	va_list parg = NULL;
//	//
//	// va_list store the address of element present in 2nd parameter in char * vari
//	//
//	va_start(parg,pszstr);
//	//
//	//vprintf print the content from parg by jumping size depending on formate spacifire.
//	//
//	iret = vprintf(pszstr,parg);
//	//
//	// va_end assing NULL to parg
//	//
//	va_end(parg);
//	return iret;
//
//}
//int sum(int itotalpara, ...)
//{
//	int iCounter;
//	int sum = 0;
//	//
//	// va_list is char *
//	//
//	va_list parg = NULL;
//	//
//	// va_list store the address of element present in 2nd parameter in char * vari
//	//
//	va_start(parg,itotalpara);
//
//	for(iCounter = 0;iCounter < itotalpara;iCounter++)
//		sum = sum + va_arg(parg,int);
//	//
//
//	va_end(parg);
//
//	return sum;
//
//}