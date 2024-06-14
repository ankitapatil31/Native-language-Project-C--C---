#include<stdio.h>
#include <conio.h>
void* function1(char *,int (*p)(int*,int*));
void* function3(char *,int (*)(int*,int*));
void* function3(char *,int (*)(int*,int*));
int function2(int*,int*);
int main()
{
    void *(*p[2])(char *,int(*)(int*,int*));
    void *ptr=NULL;
    char chChar;
	int iCounter;
   
    p[0] = function1;
    p[1] = function3;

    for(iCounter=0;iCounter<2;iCounter++)
	{
		ptr = p[iCounter](&chChar,function2);
		if(ptr != NULL)
		{
			printf("after 2nd call the charecter is:- %c",chChar);
			printf("\nIn main iAns is:- %d \n",*(int *)ptr);
		}
	}
	_getch();
    return 0;
}
void * function1(char *chChar,int (*fPtr)(int*,int*))
{
    static int iAns;
    int iNo1,iNo2;
    *chChar='A';
    printf("\nIn Function 1\n");
    iAns=fPtr(&iNo1, &iNo2);

    return &iAns;
}
void * function3(char *chChar,int (*fPtr)(int*,int*))
{
    static int iAns;
    int iNo1,iNo2;
	 *chChar='B';
    printf("\nIn Function 3\n");
    iAns=fPtr(&iNo1,&iNo2);
   
    return &iAns;
}

int function2(int *iNo1,int *iNo2)
{
	*iNo1 = 10;
	*iNo2 = 20;
    return (*iNo1)*(*iNo2);
}