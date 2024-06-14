#include<stdio.h>
#include<conio.h>
int mystrncmp(const char *,const char*,int);

int main()
{
    char string1[20],string2[20];
    int ch,iNo;
    printf("\n\nEnter String1:\t");
    gets(string1);
    printf("\n\nEnter String2:\t");
    gets(string2);
    printf("\n\nEnter n:\t");
    scanf_s("%d",&iNo);
    ch = mystrncmp(string1,string2,iNo);
    
    if(ch == 0)
        printf("\n\nBoth Strings Are Same\n");
    else
        printf("\n\nBoth Strings Are Diffrent\n");

    getch();
    return 0;
   
}
int mystrncmp(const char *pszStr1,const char *pszStr2,int iNo)
{
    int iCounter1=0;
    while( (pszStr1[iCounter1] != '\0' || pszStr2[iCounter1] != '\0') && iCounter1 < iNo )
    {
        if(pszStr1[iCounter1] != pszStr2[iCounter1])
            return 1;  
        iCounter1++;
    }
	return 0;
}