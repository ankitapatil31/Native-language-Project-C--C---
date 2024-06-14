
/*
#include<stdio.h>
#include<conio.h>
int (*(*p())[3]) ();
int fun1();
int fun2();
int fun3();
int main()
{
    int iValue,iCounter;
    int (*(*ptr)[3])()=NULL;
    ptr=p(); 
    for(iCounter=0;iCounter<3;iCounter++)
    { 
       iValue=(*(*ptr)[iCounter])();
       printf("value of INO in function %d:-%d\n",iCounter+1,iValue);
    }
   getch();
    return 0;
}
int (*(*p())[3])()
{
static int (*arr[3])();
 arr[0]=fun1;
 arr[1]=fun2;
 arr[2]=fun3;
 return arr;
}
int fun1()
{
 int iNo=10;
 return iNo;
}
int fun2()
{
 int iNo=20;       
 return iNo;
}
int fun3()
{
 int iNo=30;
 return iNo;
}
*/