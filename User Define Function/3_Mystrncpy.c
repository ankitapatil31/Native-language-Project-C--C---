#include<stdio.h>
#include<conio.h>
char * mystrncpy(char *,const char *,int);
int main()
{
	int iNo;
    char source[20];
    char destination[20];
    
    printf("\n\nEnter Source String:\t");
    gets(source);
    printf("\n\nSource String Is:\t");
    puts(source);
	printf("\n\nEnter n:\t");
    scanf_s("%d",&iNo);
    mystrncpy(destination,source,iNo);
    printf("\n\nDestination String Is:\t");
    puts(destination);
    getch();
    return 0;
}
char * mystrncpy(char *pszDestination,const char *pszSource,int iNo)
{
   
    int iCount=0;
    while(iCount < iNo && pszSource[iCount]!='\0')
    {
       pszDestination[iCount]=pszSource[iCount];
       iCount++;
    }
    pszDestination[iCount]='\0';
    return pszDestination;
}