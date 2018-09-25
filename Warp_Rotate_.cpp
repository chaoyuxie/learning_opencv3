#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImage, warpImage, rotateImage;
	Point2f srcTriangle[3], dstTriangle[3];
	srcImage = imread("2.jpg");
	namedWindow("src");
	imshow("src",srcImage);

	warpImage = Mat::zeros(srcImage.cols, srcImage.rows, srcImage.type());

	srcTriangle[0] = Point2f(0, 0);
	srcTriangle[1] = Point2f(static_cast<float>(srcImage.cols - 1), 0);
	srcTriangle[2] = Point2f(0, static_cast<float>(srcImage.rows - 1));

	dstTriangle[0] = Point2f(static_cast<float>(srcImage.cols*0.0), static_cast<float>(srcImage.rows*0.33));
	dstTriangle[1] = Point2f(static_cast<float>(srcImage.cols*0.65), static_cast<float>(srcImage.rows*0.35));
	dstTriangle[2] = Point2f(static_cast<float>(srcImage.cols*0.15), static_cast<float>(srcImage.rows*0.6));

	Mat WarpMat = getAffineTransform(srcTriangle, dstTriangle);
	warpAffine(srcImage, warpImage, WarpMat, warpImage.size());

	namedWindow("warp");
	imshow("warp", warpImage);


	Point center = Point(srcImage.cols / 2, srcImage.rows / 2);
	double angle = -30.0;	
	double scale = 0.8;	
	Mat rotMat = getRotationMatrix2D( center, angle, scale );	
	warpAffine(srcImage, rotateImage, rotMat, srcImage.size() );
	imwrite("2_rotate.jpg", rotateImage);
	
	namedWindow("rotate");
	imshow("rotate", rotateImage);

	waitKey();
	return 0;
}
