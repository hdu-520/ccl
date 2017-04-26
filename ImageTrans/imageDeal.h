
#ifndef __SHARPEN_H__ 
#define __SHARPEN_H__ 

#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include <opencv2/opencv.hpp>

#include "util.h"

using namespace cv;
using namespace std;


//图片处理类
class ImageDeal
{
public:
	//初始化成员变量
	ImageDeal(string path_src, string name_src, string type, int number);
	
	//从文件系统添加图片
	bool ReadImage(int index);

	//将读到的图片一张一张进行变换,transType代表变换类型（r：旋转，s：锐化）
	void TransImage(string transType);

	//将变换后的图片写到文件系统里 ，index用于将图片旋转变化时进行编号
	void WriteToFile(string partPath_des, string transType, int index);

	void run();


	//锐化处理
	void DoSharpen(Mat& img, Mat& result);

	//旋转变换处理,将图片旋转degree角度
	void DoRotate(Mat& img, Mat& result, int degree);

	int ReadTextData();   //读取text数据文件，并返回数据的个数（按要求）,放入 变换前的图片特征点的数据

	void VaryImageData();             //变换图片的特征点数据

	void DrawPoint(string transType);          //描点

	void TransPix();


private:
	vector<Mat > imageList_src;
	vector<Mat > imageList_des;
	Mat m_SrcImg, m_ResImg, m_DesImg;

	MyUtil* myUtil = new MyUtil();
	
	int nameLength;    //输入图片名称的长度
	int fileNumber;   //图片数量
	int targetNum;   //图片中目标的数量

	string filePath;           //图片所在目录
	string nameFormat;           // 图片名称的格式，如000001
	string imageType_src;          // 图片的格式   jpg
	string imageType_des;          // 目标图片的格式   jpg
	string fullPath_src;         // 读取文件的全路径
	string fullPath_des;          //   写入目标文件的全路径
	string file_fullName_src;
	string file_fullName_des;
	string imageName_src;
	string imageName_des;
	
	vector<double > textData_v;
	double varyData[6];                //变换图片特征点的数据
	double imageData[200][13];          //变换前的图片特征点的数据
	double imageData_vary[200][4];    //变换后的图片特征点的数据

};



#endif 
