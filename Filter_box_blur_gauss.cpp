#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat srcImage, g_dstImage1, g_dstImage2, g_dstImage3;//�洢ͼƬ��Mat����
int g_nBoxFilterValue = 3;  //�����˲�����ֵ
int g_nMeanBlurValue = 3;  //��ֵ�˲�����ֵ
int g_nGaussianBlurValue = 3;  //��˹�˲�����ֵ


static void on_BoxFilter(int, void *)
{
	//�����˲�����
	boxFilter(srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	//��ʾ����
	imshow("box", g_dstImage1);
}

static void on_blurFilter(int, void *)
{
	blur(srcImage, g_dstImage2, Size(g_nMeanBlurValue+1, g_nMeanBlurValue+1), Point(-1, -1));
	imshow("blur", g_dstImage2);
}

static void on_GaussFilter(int, void *)
{
	GaussianBlur(srcImage, g_dstImage3, Size(g_nGaussianBlurValue*2+1, g_nGaussianBlurValue*2+1), 0, 0);
	imshow("Gauss", g_dstImage3);
}

int main()
{
	srcImage = imread("2.jpg",1);
	g_dstImage1 = srcImage.clone();
	g_dstImage2 = srcImage.clone();
	g_dstImage3 = srcImage.clone();

	namedWindow("src",1);
	
	
	imshow("src",srcImage);
	namedWindow("box",1);
	createTrackbar("�ں�ֵ��", "box", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);
	imshow("box", g_dstImage1);

	namedWindow("blur",1);
	createTrackbar("�ں�ֵ��", "blur", &g_nMeanBlurValue, 40, on_blurFilter);
	on_blurFilter(g_nMeanBlurValue, 0);
	imshow("blur",g_dstImage2);
	
	namedWindow("Gauss",1);
	createTrackbar("�ں�ֵ��", "Gauss", &g_nGaussianBlurValue, 40, on_GaussFilter);
	on_blurFilter(g_nGaussianBlurValue, 0);
	imshow("Gauss", g_dstImage3);

	waitKey();
	return 0;

}

