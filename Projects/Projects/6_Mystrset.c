#include<stdio.h>
#include<conio.h>
char* mystrlwr( char *);
int main()
{
    char str[20];
    printf("\n\nEnter The String:\t");
    gets(str);
    mystrlwr(str);
    printf("\nString In Lower Case Is:\t");
    puts(str);
	getch();
return 0;
}
char* mystrlwr(char * pszStr)
{
    int iCounter=0;
    
    while(pszStr[iCounter]!='\0')
    {
        if(pszStr[iCounter] >= 65 && pszStr[iCounter] <= 90)
            pszStr[iCounter]=pszStr[iCounter]+32;

        iCounter++;
    }
    return pszStr;
}