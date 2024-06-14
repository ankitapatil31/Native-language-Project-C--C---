#include<stdio.h>
#include<conio.h>
char * mystrncat(char *,const char *,int);
int main()
{
    char source[20],destination[40];
    int n;
    printf("\n\nEnter Destination String:\t");
    gets(destination);
    printf("\n\nEnter Source String:\t");
    gets(source);
    printf("\n\nEnter Value Of n:\t");
    scanf_s("%d",&n);
    mystrncat(destination,source,n);
    printf("\n\nConcatenated String Is:\t %s",destination);
	getch();
    return 0;
}
char * mystrncat(char *pszDestination,const char *pszSource,int iNo)
{
   
    int iCounter1=0,iCounter2=0;
    while(pszDestination[iCounter1]!='\0')
        iCounter1++;
   
    while(iCounter2<iNo && pszSource[iCounter2]!='\0')
    {
        pszDestination[iCounter1]=pszSource[iCounter2];
        iCounter1++;
        iCounter2++;
    }
    pszDestination[iCounter1]='\0';
     
    return pszDestination;
}