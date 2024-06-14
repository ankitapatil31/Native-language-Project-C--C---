#include<stdio.h>
#include<wchar.h>
wchar_t wchchar = 'a';
wchar_t  wchchar1 = L'A';
int main()
{

	wchar_t wszStr[] = L"Hello";
	wchar_t *pwszStr = L"Hello";
	printf("%d",sizeof(wszStr));
	printf("%d",sizeof(pwszStr));
	getch();

}