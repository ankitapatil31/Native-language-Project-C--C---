#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NULL 0
char * mystrstr( char * pszStr1, char * pszStr2);
int main()
{
	char szStr1[50];
    char szStr2[50];
    char *ptr = NULL;
    printf("\n\nEnter String1 :\t");
    gets(szStr1);
    printf("\n\nEnter String2 :\t");
    gets(szStr2);

	ptr = mystrstr(szStr1,szStr2);
	if(NULL == ptr)
		printf("\nString Not Found");
	else
	{
		printf("String Found At %d Location ",(ptr-szStr1)+1);
		printf("\n String Found in %s \n",ptr);
	}
	getch();
	return 0 ;
}
char * mystrstr( char *pszStr1, char *pszStr2)
{
	char *ptr = NULL;
	int iCounter1 = 0,iCounter2 = 0;
	while(pszStr1[iCounter1] != '\0')
	{
		if(pszStr1[iCounter1] == pszStr2[iCounter2])
		{
			ptr = &pszStr1[iCounter1];
			while(pszStr2[iCounter2] != '\0')
			{
				if(pszStr1[iCounter1] == pszStr2[iCounter2])
				{
					iCounter1++;
					iCounter2++;
				}
				else
				{
					iCounter2 = 0;
					break;
				}
			}
			if(pszStr2[iCounter2] == '\0')
				return ptr;
			iCounter1--;
		}
		iCounter1++;
	}
	return NULL;
}