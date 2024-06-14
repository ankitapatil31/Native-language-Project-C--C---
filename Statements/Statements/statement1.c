#include<stdio.h>
void* function1(int,int (*)());
int function2();
int main()
{
	int iNo = 10;
	void *ptr = NULL;
    void *(*p)(int,int(*)());
   
    p = function1;
    ptr = p(iNo, function2);
	if(NULL != ptr)
		printf("\nIn main iAns is:- %d",*(int *)ptr);

	getch();
    return 0;
}
void * function1(int iNo,int (*fPtr)())
{
    static int iAns;
    printf("\nIn Function 1\n");
    iAns = fPtr();
    iAns = iAns+iNo;
  
    return &iAns;
}
int function2()
{
    int iNo = 10;
    printf("\nIn Function 2\n");
    return iNo;
}