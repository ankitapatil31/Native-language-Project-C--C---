#include<stdio.h>
#include<conio.h>
float ** fun2(float *,float *);
void **fun1(int *,float **(*)(float *,float *));
int main()
{
	int iNo;
	void **ptr = NULL;
	//float fNo1,fNo2;
	void **(*p)(int *,float **(*)(float *,float *));
	p=fun1;
	ptr = p(&iNo,fun2);
	if(ptr != NULL)
		printf("\nPrint Addition in fun2 :- %lf ",**(float**)ptr);

	getch();
}
float ** fun2(float *fNo1,float *fNo2)
{
	static float fNo;
	static float **fpPtr=NULL;
	static float *fptr = &fNo;
	fNo = *fNo1 + *fNo2;
	fpPtr = &fptr;

	return fpPtr;
}
void ** fun1(int *iNo,float **(*ptr)(float *,float *))
{
    float fNo1 = 10.00,fNo2 = 20.00;
	static void **fPtr = NULL;
	fPtr = (void**)ptr(&fNo1,&fNo2);
	return fPtr;
}