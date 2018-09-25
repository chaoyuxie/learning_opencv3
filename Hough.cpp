#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
 

Mat g_srcImage, g_dstImage,g_midImage;
vector<Vec4i> g_lines;

int g_nthreshold=100;

static void on_HoughLines(int, void*)
{

	Mat dstImage = g_dstImage.clone();
	Mat midImage = g_midImage.clone();

	vector<Vec4i> mylines;
	HoughLinesP(midImage, mylines, 1, CV_PI / 180, g_nthreshold + 1, 50, 10);

	for (size_t i = 0; i < mylines.size(); i++)
	{
		Vec4i l = mylines[i];
		line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(23, 180, 55), 2, CV_AA);
	}

	imshow("【效果图】", dstImage);
}

int main( )
{

	system("color 3F");  
 
	Mat g_srcImage = imread("building_03.jpg");
 
	namedWindow("【原始图】", 0);
	cvResizeWindow("【原始图】", 800, 1000);
	imshow("【原始图】", g_srcImage);  
 
	namedWindow("【效果图】", 0);
	cvResizeWindow("【效果图】", 800, 1000);
	createTrackbar("值：", "【效果图】", &g_nthreshold, 200, on_HoughLines);
 
	Canny(g_srcImage, g_midImage, 50, 200, 3);
	cvtColor(g_midImage, g_dstImage, CV_GRAY2BGR);
 
	on_HoughLines(g_nthreshold, 0);
	HoughLinesP(g_midImage, g_lines, 1, CV_PI/180, 80, 50, 10 );
 
	imshow("【效果图】", g_dstImage);  
 
	waitKey(0);  
 
	return 0;  
 
}
