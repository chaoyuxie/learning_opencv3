#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat srcImage, grayImage, dstImage;


//Canny边缘检测相关变量
Mat g_cannyDetectedEdges;
int g_cannyLowThreshold = 1;//TrackBar位置参数  

							//Sobel边缘检测相关变量
Mat g_sobelGradient_X, g_sobelGradient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize = 1;//TrackBar位置参数  

						  //Scharr滤波器相关变量
Mat g_scharrGradient_X, g_scharrGradient_Y;
Mat g_scharrAbsGradient_X, g_scharrAbsGradient_Y;
int g_scharrKernelSize = 1;

static void on_canny(int, void*)
{
	blur(grayImage, g_cannyDetectedEdges, Size(3,3));
	Canny(g_cannyDetectedEdges, g_cannyDetectedEdges, g_cannyLowThreshold, g_cannyLowThreshold*3, 3);
	dstImage = Scalar::all(0);
	srcImage.copyTo(dstImage, g_cannyDetectedEdges);
	imshow("canny", dstImage);
}

static void on_sobel(int, void*)
{
	Sobel(srcImage, g_sobelGradient_X, CV_16S, 1, 0, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);//计算绝对值，并将结果转换成8位

															 // 求Y方向梯度
	Sobel(srcImage, g_sobelGradient_Y, CV_16S, 0, 1, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y);//计算绝对值，并将结果转换成8位

															 // 合并梯度
	addWeighted(g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, dstImage);

	//显示效果图
	imshow("sobel", dstImage);

}

static void on_scharr(int, void*)
{
	// 求 X方向梯度
	Scharr(srcImage, g_scharrGradient_X, CV_16S, 1, 0, (2*g_scharrKernelSize+1), 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_X, g_scharrAbsGradient_X);//计算绝对值，并将结果转换成8位

															   // 求Y方向梯度
	Scharr(srcImage, g_scharrGradient_Y, CV_16S, 0, 1, (2* g_scharrKernelSize+1), 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_Y, g_scharrAbsGradient_Y);//计算绝对值，并将结果转换成8位

															   // 合并梯度
	addWeighted(g_scharrAbsGradient_X, 0.5, g_scharrAbsGradient_Y, 0.5, 0, dstImage);

	//显示效果图
	imshow("scharr", dstImage);
}


int main()
{
	srcImage = imread("windows.jpg");

	namedWindow("【原始图】");
	imshow("【原始图】", srcImage);

	// 创建与src同类型和大小的矩阵(dst)
	dstImage.create(srcImage.size(), srcImage.type());

	// 将原图像转换为灰度图像
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);
	namedWindow("canny");
	createTrackbar("参数值：", "canny", &g_cannyLowThreshold, 120, on_canny);
	on_canny(g_cannyLowThreshold, 0);

	namedWindow("scharr");
	createTrackbar("参数值：", "scharr", &g_scharrKernelSize, 120, on_scharr);
	on_scharr(g_scharrKernelSize, 0);

	namedWindow("sobel");
	createTrackbar("参数值：", "sobel", &g_sobelKernelSize, 3, on_sobel);
	on_sobel(g_sobelKernelSize, 0);

	waitKey();
	return 0;

}