#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

Mat srcImage, erodeImage, dilateImage, openImage, closeImage, topImage, blackImage, gradImage;
int SizeValue = 3, dilateVlaue = 3, erodeVlaue = 3, openValue = 3, closeValue = 3, topValue = 3, blackValue = 3, gradValue = 3;

static void on_erode(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	erode(srcImage, erodeImage, element);
	imshow("Process_image", erodeImage);
}

static void on_dilate(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	dilate(srcImage, dilateImage, element);
	imshow("Process_image", dilateImage);
}

static void on_open(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	morphologyEx(srcImage, openImage, MORPH_OPEN, element);
	imshow("Process_image", openImage);
}

static void on_close(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	morphologyEx(srcImage, closeImage, MORPH_CLOSE, element);
	imshow("Process_image", closeImage);
}

static void on_top(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	morphologyEx(srcImage, topImage, MORPH_TOPHAT, element);
	imshow("Process_image", topImage);
}

static void on_black(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	morphologyEx(srcImage, blackImage, MORPH_BLACKHAT, element);
	imshow("Process_image", blackImage);
}

static void on_drad(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	morphologyEx(srcImage, gradImage, MORPH_GRADIENT, element);
	imshow("Process_image", gradImage);
}


int main()
{
	srcImage = imread("beach.jpg");
	namedWindow("src");
	imshow("src",srcImage);
	namedWindow("Process_image");
	createTrackbar("dilate", "Process_image", &SizeValue, 30, on_dilate);
	on_dilate(SizeValue, 0);
	createTrackbar("erode", "Process_image", &SizeValue, 30, on_erode);
	on_dilate(SizeValue, 0);
	createTrackbar("close", "Process_image", &SizeValue, 30, on_close);
	on_dilate(SizeValue, 0);
	createTrackbar("open", "Process_image", &SizeValue, 30, on_open);
	on_dilate(SizeValue, 0);
	createTrackbar("top", "Process_image", &SizeValue, 30, on_top);
	on_dilate(SizeValue, 0);
	createTrackbar("black", "Process_image", &SizeValue, 30, on_black);
	on_dilate(SizeValue, 0);
	createTrackbar("grad", "Process_image", &SizeValue, 30, on_drad);
	on_dilate(SizeValue, 0);
	waitKey();
	return 0;
}