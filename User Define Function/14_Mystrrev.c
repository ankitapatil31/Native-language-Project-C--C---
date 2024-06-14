#include<stdio.h>
#include<string.h>
#include<conio.h>
char* mystrrev(char * pszStr);
int main()
{
    char str[20];
    printf("\n\nEnter The String:\t");
    gets(str);
    mystrrev(str);
    printf("\nString In Reverse Order :-\t");
    puts(str);
	getch();
	return 0;
}
char* mystrrev(char * pszStr)
{
    int iCounter1 = 0,iCounter2 = 0;

    while(pszStr[iCounter1]!='\0')
		iCounter1++;

	iCounter1--;
	while(iCounter2<iCounter1)
	{
		pszStr[iCounter1] = pszStr[iCounter1] + pszStr[iCounter2];
		pszStr[iCounter2] = pszStr[iCounter1] - pszStr[iCounter2];
		pszStr[iCounter1] = pszStr[iCounter1] - pszStr[iCounter2]; 

		iCounter2++;
		iCounter1--;
	}
    return pszStr;
}
