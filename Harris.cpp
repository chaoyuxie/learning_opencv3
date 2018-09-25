#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat srcImage, srcImage2, grayImage;
int thresh = 20;
int max_thresh = 150;

static void on_harris(int, void*)
{
	Mat dstImage, normImage, scaledImage;
	dstImage = Mat::zeros(srcImage.size(), CV_32FC1);
	srcImage2 = srcImage.clone();
	cornerHarris(grayImage, dstImage, 2, 3, 0.04, BORDER_DEFAULT);
	normalize(dstImage, normImage, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(normImage, scaledImage);

	for (int j = 0; j < normImage.rows; j++)
	{
		for (int i = 0; i < normImage.cols; i++)
		{
			if ((int)normImage.at<float>(j, i) > thresh + 80)
			{
				circle(srcImage2, Point(i, j), 5, Scalar(10, 10, 255), 2, 8, 0);

				circle(scaledImage, Point(i, j), 5, Scalar(0, 10, 255), 2, 8, 0);
			}
		}
	}
	imshow("src_1", srcImage2);
	imshow("src_2", scaledImage);

}


int main()
{
	srcImage = imread("building_03.jpg");
	srcImage2 = srcImage.clone();
	cvtColor(srcImage2, grayImage, CV_BGR2GRAY);
	namedWindow("src", 0);
	cvResizeWindow("src", 400, 500);
	imshow("src", srcImage);

	namedWindow("src_1", 0);
	namedWindow("src_2", 0);
	cvResizeWindow("src_1", 400, 500);
	cvResizeWindow("src_2", 400, 500);
	createTrackbar("„–÷µ£∫", "src_1", &thresh, max_thresh, on_harris);
	on_harris(0, 0);
	waitKey();
	return 0;

}