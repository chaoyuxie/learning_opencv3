#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

Mat srcImage, erodeImage, dilateImage;
int SizeValue = 3, dilateVlaue = 3, erodeVlaue = 3;

static void on_erode(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2*SizeValue+1, 2*SizeValue+1));
	erode(srcImage, erodeImage, element);
	imshow("Process_image", erodeImage);
}

static void on_dilate(int, void*)
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * SizeValue + 1, 2 * SizeValue + 1));
	dilate(srcImage, dilateImage, element);
	imshow("Process_image", dilateImage);
}

int main()
{
	srcImage = imread("2.jpg",1);
	namedWindow("src");
	imshow("src",srcImage);
	namedWindow("Process_image",1);
	createTrackbar("dilate", "Process_image", &SizeValue, 30, on_dilate);
	on_dilate(SizeValue, 0);
	createTrackbar("erode", "Process_image", &SizeValue, 30, on_erode);
	on_dilate(SizeValue, 0);
	waitKey();
	return 0;

}