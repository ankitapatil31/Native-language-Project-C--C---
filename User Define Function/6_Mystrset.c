#include<stdio.h>
#include<conio.h>
char * mystrset(char *,char);
int main()
{
	char chChar,szStr[20];
	printf("\n\nEnter The String:\t");
    gets(szStr);
	printf("\nEnter the charecter to be set:-");
	scanf("%c",&chChar);

	mystrset(szStr,chChar);

	printf("\nNow String is:-\t %s",szStr);
	getch();
}
char * mystrset(char *pszStr,char chChar)
{
	int iCounter=0;
	while(pszStr[iCounter] != '\0')
	{
		pszStr[iCounter] = chChar;
		iCounter++;
	}
	return pszStr;
}