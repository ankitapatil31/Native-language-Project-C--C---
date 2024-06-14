
#include<stdio.h>
#include<conio.h>
int * fun1(int *);
int * fun2(int *);
int * fun3(int *);
int main()
{
    int iCounter1,iCounter2,iNo = 10;
    int (*(*p[3])(int *));
    int (*ptr)=NULL;
    
    p[0]=fun1;
    p[1]=fun2;
    p[2]=fun3;
	for(iCounter1 = 0; iCounter1 <= 2; iCounter1++)
	{
		printf("Print the value of function%d :- ",iCounter1,"\n");
		ptr = p[iCounter1](&iNo);
		if(ptr != NULL)
		{
			for(iCounter2=0;iCounter2 < 2;iCounter2++)
			{
				printf("%d  ",ptr[iCounter2]);
			}
		}
		printf("\n");
	}
	_getch();
    return 0;
}
int * fun1(int * iNo)
{
	static int arr[2]={20};
	arr[1] = *iNo;
    return arr;
}
int * fun2(int * iNo)
{
    static int arr[2]={30};
	arr[1] = *iNo;
    return arr;
}
int * fun3(int * iNo)
{
    static int arr[2]={40};
	arr[1] = *iNo;
    return arr;
}