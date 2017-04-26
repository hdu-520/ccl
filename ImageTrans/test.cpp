////
//// Created by chen on 17-4-20.
////
//#include "stdio.h"
//#include "iostream"
//
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//// 获取指定像素点放射变换后的新的坐标位置
////Point getPointAffinedPos(const Point &src, const Point ¢er, double angle);
////Mat ImageRotate(Mat & src, const Point &_center, double angle);
//
//Point getPointAffinePos(const Point &src, const Point center, double angle);
//Mat ImageRotate(Mat &src, const Point &_center, double angle);
//
//int main()
//{
//    string image_path = "/home/chen/Desktop/tanke_all/image/002001.jpg";
//    Mat img = imread(image_path);
//    double angle = 60L;
//
//    Mat src;
//    img.copyTo(src);
//
//    Point center;
//    center.x = img.cols / 2;
//    center.y = img.rows / 2;
//
//    Mat dst = ImageRotate(img, center, angle);
//
//
//    Point p1(538, 539), p2(678, 693);
//
//    rectangle(img, p1, p2, Scalar(0, 0, 255), 3, 8, 0);
//    imshow("src", img);
//
//    // 计算原特征点在旋转后图像中的对应的坐标
//    Point l1 = getPointAffinePos(p1, center, angle * CV_PI / 180);
//    Point l2 = getPointAffinePos(p2, center, angle * CV_PI / 180);
//
//
//    rectangle(dst, l1, l2, Scalar(0, 0, 255), 3, 8, 0);
//    imshow("dst", dst);
//
//    waitKey(0);
//    return 0;
//}
//
//Mat ImageRotate(Mat & src, const Point &_center, double angle)
//{
//    CvPoint2D32f center;
//    center.x = float(_center.x);
//    center.y = float(_center.y);
//
//    //计算二维旋转的仿射变换矩阵
//    Mat M = getRotationMatrix2D(center, angle, 1);
//
//    // rotate
//    Mat dst;
//    warpAffine(src, dst, M, cvSize(src.cols, src.rows), CV_INTER_LINEAR);
//    return dst;
//}
//
//// 获取指定像素点放射变换后的新的坐标位置
//Point getPointAffinePos(const Point &src, const Point center, double angle)
//{
//    CvPoint dst;
//    int x = src.x - center.x;
//    int y = src.y - center.y;
//
//    dst.x = cvRound(x * cos(angle) + y * sin(angle) + center.x);
//    dst.y = cvRound(-x * sin(angle) + y * cos(angle) + center.y);
//    return dst;
//}
