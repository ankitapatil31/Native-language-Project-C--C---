//#include<stdio.h>
//void fun(int n,int k)
//{
//	int iCounter1,iCounter2;
//	int iand = 0,itemp = 0,ior=0,ixor = 0;
//	for(iCounter1 =1 ;iCounter1<=n;iCounter1++)
//	{
//		for(iCounter2 =iCounter1+1;iCounter2<=n;iCounter2++)
//		{
//			itemp = iCounter1 & iCounter2;
//			if((itemp < k) && (iand <= itemp))
//				iand = itemp;
//			itemp = iCounter1 | iCounter2;
//			if((itemp < k) && (ior <= itemp))
//				ior = itemp;
//			itemp = iCounter1 ^ iCounter2;
//			if((itemp < k) && (ixor <= itemp))
//				ixor = itemp;
//		}
//	}
//	printf("%d\n%d\n%d" ,iand,ior,ixor);
//}
//int main()
//{
//	int n,k;
//	fun(5,4);
//	getch();
//
//}