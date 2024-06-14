#include<stdio.h>
#include<conio.h>
char * mystrcat(char *,const char *);
int main()
{
    char source[20],destination[40];
    printf("\n\nEnter Destination String:\t");
    gets(destination);
    printf("\n\nEnter Source String:\t");
    gets(source);
    mystrcat(destination,source);
    printf("\n\nConcatenated String Is:\t");
    puts(destination);
	getch();
    return 0;
}
char * mystrcat(char *pszDestination,const char *pszSource)
{
   
    int iCounter1=0,iCounter2=0;
    while(pszDestination[iCounter1]!='\0')
        iCounter1++;
   
    while(pszSource[iCounter2]!='\0')
    {
        pszDestination[iCounter1]=pszSource[iCounter2];
        iCounter1++;
        iCounter2++;
    }
    pszDestination[iCounter1]='\0';
     
    return pszDestination;
}
