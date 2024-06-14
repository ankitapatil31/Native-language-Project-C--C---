#include<stdio.h>
#include<string.h>
#include<conio.h>
int mystrncmpi(const char *,const char *,int);
int main()
{
	int chChar,iNo;
    char szStr1[20];
    char szStr2[20];
    
    printf("\n\nEnter String1 :\t");
    gets(szStr1);
    printf("\n\nEnter String2 :\t");
    gets(szStr2);
	printf("\n\nEnter No :\t");
    scanf("%d",&iNo);
	chChar = mystrncmpi(szStr1,szStr2,iNo);

	if(chChar == 0)
		printf("\nBoth String Are Same\n");
	else
		printf("\nBoth String Are Different");

	getch();
	return 0;
}
int mystrncmpi(const char *pszStr1,const char *pszStr2,int iNo)
{
	int iCounter=0;
	while((pszStr1[iCounter] != '\0' || pszStr2[iCounter] != '\0') && iCounter < iNo )
	{
		if(pszStr1[iCounter] != pszStr2[iCounter] && pszStr1[iCounter]+32 != pszStr2[iCounter] && pszStr2[iCounter] != pszStr1[iCounter] && pszStr2[iCounter]+32 != pszStr1[iCounter])
			return 1;
		iCounter++;
	}
	return 0;
}