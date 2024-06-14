#include<stdio.h>
#include<conio.h>
char* mystrupr( char *);
int main()
{
    char str[20];
    printf("\n\nEnter The String:\t");
    gets(str);
    mystrupr(str);
    printf("\nString In Lower Case Is:\t");
    puts(str);
	getch();
return 0;
}
char* mystrupr(char * pszStr)
{
    int iCounter=0;
    
    while(pszStr[iCounter]!='\0')
    {
        if(pszStr[iCounter] >= 97 && pszStr[iCounter] <= 122)
            pszStr[iCounter]=pszStr[iCounter]-32;

        iCounter++;
    }
    return pszStr;
}