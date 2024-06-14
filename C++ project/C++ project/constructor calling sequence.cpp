/////*
////	constructor initalization List
////	karan jar base ne default nhi dila tr complier default style ch constructor 
////	nhi deu shakat  and para to call nhi karu shakat derived madhun mg ambiguty
////	yete mhnun apan dyava or derived madhe constructor initalization list dyavi.
////	
////*/
////#include<iostream>
////using namespace std;
////class demo
////{
////public:
////	demo(int ino)
////	{
////		cout<<"base";
////	}
////};
////class derived:public demo
////{
////public:
////	derived():demo(10)						// construcor init list...
////	{
////		cout<<"derived";
////	}
////};
////int main()
////{
////	derived dob;
////}
//
//#include<iostream>
//#include<string>
//using namespace std;
//class test
//{
//public:
//	operator string()
//	{
//		return"hii";
//	}
//};
//int main()
//{
//	test t;
//	string s =  t;
//	cout<< s <<endl;
//	cin.get();
//	return 0;
//}