#include<stdio.h>
#include<conio.h>
char * mystrnset(char *,char,int);
int main()
{
	int iNo;
	char chChar,szStr[20];
	printf("\n\nEnter The String:\t");
    gets(szStr);
	printf("\nEnter the charecter to be set:-");
	scanf("%c",&chChar);

	printf("\n\nEnter n:\t");
    scanf_s("%d",&iNo);
	mystrnset(szStr,chChar,iNo);

	printf("\nNow String is:-\t %s",szStr);
	getch();
}
char * mystrnset(char *pszStr,char chChar,int iNo)
{
	int iCounter=0;
	while(iCounter < iNo && pszStr[iCounter] != '\0')
	{
		pszStr[iCounter] = chChar;
		iCounter++;
	}
	return pszStr;
}