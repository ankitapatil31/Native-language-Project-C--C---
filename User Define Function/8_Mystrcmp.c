#include<stdio.h>
#include<conio.h>
int mystrcmp(const char *,const char *);
int main()
{
    
    char string1[20],string2[20];
    int ch;
    printf("\n\nEnter String1:\t");
    gets(string1);
    printf("\n\nEnter String2:\t");
    gets(string2);

    ch = mystrcmp(string1,string2);

    if(ch == 0)
        printf("\n\nBoth Strings Are Same\n");
    else
        printf("\n\nBoth Strings Are Diffrent\n");

    getch();
    return 0;
}
int mystrcmp(const char *pszStr1,const char *pszStr2)
{
    int iCounter1=0;
    
    while(pszStr1[iCounter1] != '\0' && pszStr2[iCounter1] != '\0')
    {
        if(pszStr1[iCounter1] != pszStr2[iCounter1])
            return 1;
            
        iCounter1++;
    }
	return 0;
}

