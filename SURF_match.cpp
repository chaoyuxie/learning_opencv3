#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/nonfree/nonfree.hpp>
#include<opencv2/legacy/legacy.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImage1, srcImage2;
	srcImage1 = imread("2.jpg");
	srcImage2 = imread("2_rotate.jpg");
	int minHessian = 7000;
	SurfFeatureDetector detector(minHessian);
	vector<KeyPoint> img_keypoint_1, img_keypoint_2;
	detector.detect(srcImage1, img_keypoint_1);
	detector.detect(srcImage2, img_keypoint_2);

	SurfDescriptorExtractor extractor;
	Mat descriptor1, descriptor2;
	extractor.compute(srcImage1, img_keypoint_1, descriptor1);
	extractor.compute(srcImage2, img_keypoint_2, descriptor2);
	BruteForceMatcher<L2<float>> matcher;
	vector<DMatch>matches;
	matcher.match(descriptor1, descriptor2, matches);
	Mat imgMatches;
	drawMatches(srcImage1, img_keypoint_1, srcImage2, img_keypoint_2, matches, imgMatches);
	namedWindow("detect");
	imshow("detect", imgMatches);
	waitKey();
	return 0;


}
