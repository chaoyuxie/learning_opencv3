#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/nonfree/nonfree.hpp>

using namespace std;
using namespace cv;

int minHessian = 400;
Mat srcImage1, srcImage2;

static void on_surf(int, void*)
{
	SurfFeatureDetector detector(minHessian);
	vector<KeyPoint>keypoints_1;
	detector.detect(srcImage1, keypoints_1);
	Mat img_1,;
	drawKeypoints(srcImage1, keypoints_1, img_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	imshow("dst_1", img_1);
}



int main()
{
	srcImage1 = imread("2_3.jpg");
	namedWindow("src1");
	imshow("src1",srcImage1);

	namedWindow("dst_1");
	createTrackbar("„–÷µ£∫", "dst_1", &minHessian, 5000, on_surf);
	on_surf(minHessian,0);

	waitKey();
	return 0;
}