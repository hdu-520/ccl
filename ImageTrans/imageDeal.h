
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


//ͼƬ������
class ImageDeal
{
public:
	//��ʼ����Ա����
	ImageDeal(string path_src, string name_src, string type, int number);
	
	//���ļ�ϵͳ���ͼƬ
	bool ReadImage(int index);

	//��������ͼƬһ��һ�Ž��б任,transType����任���ͣ�r����ת��s���񻯣�
	void TransImage(string transType);

	//���任���ͼƬд���ļ�ϵͳ�� ��index���ڽ�ͼƬ��ת�仯ʱ���б��
	void WriteToFile(string partPath_des, string transType, int index);

	void run();


	//�񻯴���
	void DoSharpen(Mat& img, Mat& result);

	//��ת�任����,��ͼƬ��תdegree�Ƕ�
	void DoRotate(Mat& img, Mat& result, int degree);

	int ReadTextData();   //��ȡtext�����ļ������������ݵĸ�������Ҫ��,���� �任ǰ��ͼƬ�����������

	void VaryImageData();             //�任ͼƬ������������

	void DrawPoint(string transType);          //���

	void TransPix();


private:
	vector<Mat > imageList_src;
	vector<Mat > imageList_des;
	Mat m_SrcImg, m_ResImg, m_DesImg;

	MyUtil* myUtil = new MyUtil();
	
	int nameLength;    //����ͼƬ���Ƶĳ���
	int fileNumber;   //ͼƬ����
	int targetNum;   //ͼƬ��Ŀ�������

	string filePath;           //ͼƬ����Ŀ¼
	string nameFormat;           // ͼƬ���Ƶĸ�ʽ����000001
	string imageType_src;          // ͼƬ�ĸ�ʽ   jpg
	string imageType_des;          // Ŀ��ͼƬ�ĸ�ʽ   jpg
	string fullPath_src;         // ��ȡ�ļ���ȫ·��
	string fullPath_des;          //   д��Ŀ���ļ���ȫ·��
	string file_fullName_src;
	string file_fullName_des;
	string imageName_src;
	string imageName_des;
	
	vector<double > textData_v;
	double varyData[6];                //�任ͼƬ�����������
	double imageData[200][13];          //�任ǰ��ͼƬ�����������
	double imageData_vary[200][4];    //�任���ͼƬ�����������

};



#endif 
