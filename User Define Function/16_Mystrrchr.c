#include<stdio.h>
#include<conio.h>
#include<string.h>
const char * mystrrchr(const char *,char);
int main()
{
	char szStr[20],chChar;
    char *pszStr;
	printf("\nEnter The String:-\t");
	gets(szStr);

	printf("\nEnter The Charecter To Be Found:-\t");
	scanf("%c",&chChar);

	pszStr = mystrrchr(szStr,chChar);

	if(pszStr == NULL)
		printf(" \nCharecter not found\n");
	else
		printf("\nCharecter to be Found at %d Location\n",(pszStr-szStr)+1);
	getch();
	return 0;
}
const char * mystrrchr(const char *pszStr,char chChar)
{
	int iCounter = 0;
	const char * ptr= NULL;
	while(pszStr[iCounter] != '\0')
	{
		if(pszStr[iCounter] == chChar)
			ptr =  &pszStr[iCounter];
		iCounter++;
	}
	return ptr;
	
	return 0;
}
/*
	# Another Logic :- 

	while(pszStr[iCounter] != '\0')
	{iCounter++;}
	iCounter--;
	while(iCounter != 0)
	{
		if(pszStr[iCounter] == chChar)
			return &pszStr[iCounter];
		iCounter--;
	} 
*/