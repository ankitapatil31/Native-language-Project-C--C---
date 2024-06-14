#include<stdio.h>
#include<conio.h>
int mystrlen(const char *pszStr);
int main()
{
    char *ptr="Hello";
    char str[]="Good";
    printf("\nThe Length Of Hello Is %d\n",mystrlen(ptr));
    printf("The Length Of Good Is %d\n",mystrlen(str));
    printf("The Length Of Morning Is %d\n",mystrlen("Morning"));
	getch();
    return 0;
}
int mystrlen(const char *pszStr)
{
    int iCount=0;
    while(pszStr[iCount]!='\0')
    {
        iCount++;
    }  
    return iCount;
}