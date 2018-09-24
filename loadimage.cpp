#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat windows_picture = imread("RWj3Zn_1920x1080.jpg");
	namedWindow("windows_pictures", (320,320));
	imshow("windows_pictures",windows_picture);

	Mat image1 = imread("1.jpg");
	Mat image2 = imread("2.jpg");
	namedWindow("1");
	imshow("1", image1);
	namedWindow("2");
	imshow("2", image2);

	Mat imageROI;
	//·½·¨Ò»
	imageROI = windows_picture(Rect(1200, 350, image1.cols, image1.rows));

	addWeighted(imageROI, 0.5, image1, 0.3, 0., imageROI);
	namedWindow("1+..");
	imshow("1+..", windows_picture);

	imwrite("wefew.jpg", windows_picture);
	waitKey();
}