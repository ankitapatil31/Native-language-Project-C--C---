#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat img = imread("demo.jpg");
	namedWindow("image",WINDOW_NORMAL);
	imshow("image", img);
	return 0;

}