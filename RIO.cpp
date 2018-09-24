#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat srcImage = imread("windows.jpg");
	Mat logoImage = imread("2.jpg");

	Mat ImageRio = srcImage(Rect(1500,700, logoImage.cols, logoImage.rows));

	//Mat mask = imread("2.jpg",0);
	//logoImage.copyTo(ImageRio, mask);

	namedWindow("GPA");
	imshow("GPA",srcImage);

	Mat Image;// = Rect(0, 0, srcImage.cols, srcImage.rows);
	addWeighted(ImageRio, 0.3, logoImage, 0.1, 0. , Image);
	Mat mask = imread("2.jpg",0);
	Image.copyTo(ImageRio, mask);
	namedWindow("GPA2");
	imshow("GPA2", srcImage);
	waitKey();
	return 0;

}
