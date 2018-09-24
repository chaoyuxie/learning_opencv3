#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;



int main()
{
	Mat srcImage = imread("windows.jpg");
	Mat LogoImage = imread("2.jpg",0);
	vector<Mat> channels;
	Mat imageBlueChannel, imageRedChannel, imageGreenChannel,ImageRio;
	split(srcImage, channels);
	imageBlueChannel = channels.at(0);
	ImageRio = imageBlueChannel(Rect(1400, 100, LogoImage.cols, LogoImage.rows));
	addWeighted(ImageRio,1.0, LogoImage, 0.5, 0., ImageRio);
	merge(channels, srcImage);
	namedWindow("Merge");
	imshow("Merge", srcImage);

	srcImage = imread("windows.jpg");
	LogoImage = imread("2.jpg", 0);
	split(srcImage, channels);
	imageGreenChannel = channels.at(1);
	ImageRio = imageGreenChannel(Rect(1400, 100, LogoImage.cols, LogoImage.rows));
	addWeighted(ImageRio, 1.0, LogoImage, 0.5, 0., ImageRio);
	merge(channels, srcImage);
	namedWindow("MergeGreen");
	imshow("MergeGreen", srcImage);

	srcImage = imread("windows.jpg");
	LogoImage = imread("2.jpg", 0);
	split(srcImage, channels);
	imageRedChannel = channels.at(2);
	ImageRio = imageRedChannel(Rect(1400, 100, LogoImage.cols, LogoImage.rows));
	addWeighted(ImageRio, 1.0, LogoImage, 0.5, 0., ImageRio);
	merge(channels, srcImage);
	namedWindow("MergeRED");
	imshow("MergeRED", srcImage);
	waitKey();
	return 0;
}
