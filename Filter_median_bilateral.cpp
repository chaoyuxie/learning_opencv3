#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

Mat srcImage, medianImage, bilateralImage;

int medianValue = 5;
int bilateralValue = 5;

static void on_Median(int, void*)
{
	medianBlur(srcImage, medianImage, medianValue*2+1);
	imshow("median",medianImage);
}

static void on_Bilateral(int, void*)
{
	bilateralFilter(srcImage, bilateralImage, bilateralValue, bilateralValue*2, bilateralValue/2);
	imshow("bilater", bilateralImage);
}

int main()
{
	srcImage = imread("2.jpg");
	namedWindow("src");
	imshow("src",srcImage);
	medianImage = srcImage.clone();
	bilateralImage = srcImage.clone();
	namedWindow("median");
	createTrackbar("参数值：", "median", &medianValue, 50, on_Median);
	on_Median(medianValue, 0);

	namedWindow("bilater");
	createTrackbar("参数值：", "bilater", &bilateralValue, 50, on_Bilateral);
	on_Bilateral(bilateralValue, 0);

	waitKey();
	return 0;

}