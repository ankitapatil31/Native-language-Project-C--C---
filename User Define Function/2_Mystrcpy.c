#include<stdio.h>
#include<conio.h>
char * mystrcpy(char *,const char *);
int main()
{
    char source[20];
    char destination[20];
    
    printf("\n\nEnter Source String:\t");
    gets(source);
    printf("\n\nSource String Is:\t");
    puts(source);
    mystrcpy(destination,source);
    printf("\n\nDestination String Is:\t");
    puts(destination);
    getch();
    return 0;
}
char * mystrcpy(char *pszDestination,const char *pszSource)
{
   
    int iCount=0;
    while(pszSource[iCount]!='\0')
    {
       pszDestination[iCount]=pszSource[iCount];
       iCount++;
    }
    pszDestination[iCount]='\0';
    return pszDestination;
}
