#include"imageDeal.h"
#include"define.h"
#include <fstream>

//初始化成员变量
ImageDeal::ImageDeal(string path_src, string name_src, string type, int number_src)
{
	filePath = path_src;
	imageName_src = name_src;
	nameFormat = name_src;
	imageType_src = type;
	imageType_des = type;
	fileNumber = number_src;
	nameLength = nameFormat.length();

	/*imageList_src.resize(1);
	imageList_des.resize(1);*/

}


//读取text数据文件，并返回数据的个数（按要求）,放入 变换前的图片特征点的数据
int ImageDeal::ReadTextData()
{
	//将每个标签点存入数组
	int car_num = textData_v.size() / 13, n = 0;
	for (int i = 0; i < car_num; i++) {
		for (int j = 0; j < 13; j++) {
			imageData[i][j] = textData_v[n];
			n++;
		}
	}
	//清除当前车辆的数据信息
	textData_v.clear();
	n = 0;

	for (int i = 0; i < car_num; i++) {
		if (imageData[i][9] <= 0) {
			imageData[i][9] = 3;
		}
		else if (imageData[i][10] <= 0) {
			imageData[i][10] = 3;
		}
	}

	return car_num;
}

//从文件系统读取图片信息，包括txt
bool ImageDeal::ReadImage(int index)
{
	//读图片
	myUtil->int_str(index, imageName_des, HAVEFORMAT, nameLength);
	myUtil->ChangeName(file_fullName_src, imageName_des, imageType_src);
	myUtil->ChangePath(filePath, fullPath_src, file_fullName_src);
//	if (!myUtil->ReadImage(fullPath_src, m_SrcImg))
//		return false;
	m_SrcImg = imread(fullPath_src);

	//读标签数据
//	string tempPath = filePath;
//	string s;
//	myUtil->int_str(index, s, NOFORMAT, 0);
//	tempPath += "../data/" + s + ".txt";
//	myUtil->ReadText(textData_v, tempPath);
//
//	targetNum = ReadTextData();
	if(m_SrcImg.data==NULL)
		return false;

	return true;
}

//将读到的图片一张一张进行变换
void ImageDeal::TransImage(string transType)
{
	if (transType == "ROTATE")
	{
		for (int i = 1; i < 6; i++)
		{
			DoRotate(m_SrcImg, m_ResImg, 60 * i);
			//变换标签数据
			//VaryImageData();
			//DrawPoint("ROTATE");
			imageList_des.push_back(m_ResImg);
		}
	}
	else if (transType == "SHARPEN")
	{
		//imshow("ffsdf",m_SrcImg);
		DoSharpen(m_SrcImg, m_ResImg);
		//imshow("ffsdf",m_ResImg);
		//DrawPoint("SHARPEN");
		//imageList_des.push_back(m_ResImg);
	}
		
}

//将变换后的图片写到文件系统里
void ImageDeal::WriteToFile(string partPath_des, string transType, int index)
{
	string temp = imageName_des;

	if (transType == "SHARPEN" && index == -1)
	{
		//temp += "_s";
		temp[0]='7';
		temp[1]='1';
		fullPath_des = filePath + partPath_des + temp + "." + imageType_des;
		imwrite(fullPath_des, m_ResImg);
	}
	else if (transType == "ROTATE" && index != -1)
	{
		string s;
		myUtil->int_str(index, s, NOFORMAT, nameLength);
		temp[0]='8';
		temp[1] = s[0];
		fullPath_des = filePath + partPath_des + temp + "." + imageType_des;
		imwrite(fullPath_des, imageList_des[index-1]);
	}
}


void ImageDeal::DoSharpen(Mat& img, Mat& result)
{

	//创建一张空白图片
	result.create(img.size(), img.type());
	//处理边界内部的像素点, 图像最外围的像素点应该额外处理
	for (int row = 1; row < img.rows - 1; row++)
	{
		//前一行像素点
		const uchar* previous = img.ptr<const uchar>(row - 1);
		//待处理的当前行
		const uchar* current = img.ptr<const uchar>(row);
		//下一行像素点
		const uchar* next = img.ptr<const uchar>(row + 1);
		uchar *output = result.ptr<uchar>(row);
		int ch = img.channels();
		int starts = ch;
		int ends = (img.cols - 1) * ch;
		for (int col = starts; col < ends; col++)
		{
			//输出图像的遍历指针与当前行的指针同步递增, 以每行的每一个像素点的每一个通道值为一个递增量, 因为要考虑到图像的通道数
			*output++ = saturate_cast<uchar>(5 * current[col] - current[col - ch] - current[col + ch] - previous[col] - next[col]);
		}
	} //end loop

	  //处理边界, 外围像素点设为 0
	result.row(0).setTo(Scalar::all(0));
	result.row(result.rows - 1).setTo(Scalar::all(0));
	result.col(0).setTo(Scalar::all(0));
	result.col(result.cols - 1).setTo(Scalar::all(0));

}

//旋转变换处理,将图片旋转degree角度
void ImageDeal::DoRotate(Mat& img, Mat& result, int degree)
{
	double angle = degree * CV_PI / 180.; // 旋转角度
	double a = sin(angle), b = cos(angle);
	int width = img.cols;
	int height = img.rows;
	int width_rotate = int(height * fabs(a) + width * fabs(b));
	int height_rotate = int(width * fabs(a) + height * fabs(b));

	//生成仿射变换矩阵
	float map[6];
	Mat map_matrix = Mat(2, 3, CV_32F, map);
	CvPoint2D32f center = cvPoint2D32f(width / 2, height / 2);
	CvMat map_matrix2 = map_matrix;
	cv2DRotationMatrix(center, degree, 1.0, &map_matrix2);
	map[2] += (width_rotate - width) / 2;
	map[5] += (height_rotate - height) / 2;

	Mat img_rotate;
	float *tmp = (float *)map_matrix.data;
	warpAffine(img, img_rotate, map_matrix, Size(width_rotate, height_rotate), 1, 0, 0);	//仿射变换函数
	for (int i = 0; i < 6; i++) {
		varyData[i] = tmp[i];
	}
    string path="/home/chen/Desktop/"+to_string(degree)+".txt";

    ofstream fileWrite(path, ios::in);
    if(fileWrite.is_open())
    {
        for (int i = 0; i < 6; i++)
        {
            fileWrite << varyData[i] << endl;
        }
    }
    fileWrite.close();

	result=img_rotate;	//旋转变换后的图片
}

//变换图片的特征点数据
void ImageDeal::VaryImageData()
{
	//将标签数据的坐标点仿射变换
	for (int j = 0; j < targetNum; j++) {
		imageData_vary[j][0] = imageData[j][9] * varyData[0] + imageData[j][10] * varyData[1] + varyData[2];
		imageData_vary[j][1] = imageData[j][9] * varyData[3] + imageData[j][10] * varyData[4] + varyData[5];
		imageData_vary[j][2] = (imageData[j][9] + imageData[j][11]) * varyData[0] + (imageData[j][10] + imageData[j][12]) * varyData[1] + varyData[2];
		imageData_vary[j][3] = (imageData[j][9] + imageData[j][11]) * varyData[3] + (imageData[j][10] + imageData[j][12]) * varyData[4] + varyData[5];
	}
}

//描点
void ImageDeal::DrawPoint(string transType)
{
	//显示标签数据的定位点
	Point center;
	for (int j = 0; j < targetNum; j++) {
		if (transType == "ROTATE")
		{
			center.x = imageData_vary[j][0];
			center.y = imageData_vary[j][1];
			circle(m_ResImg, center, 3, Scalar(255, 255, 0), -1);
			center.x = imageData_vary[j][2];
			center.y = imageData_vary[j][3];
			circle(m_ResImg, center, 3, Scalar(255, 255, 0), -1);
			
		}
		if (transType == "SHARPEN")
		{
			center.x = imageData[j][0];
			center.y = imageData[j][1];
			circle(m_ResImg, center, 3, Scalar(255, 255, 0), -1);
			center.x = imageData[j][2];
			center.y = imageData[j][3];
			circle(m_ResImg, center, 3, Scalar(255, 255, 0), -1);
		}
	}
}


//修改图像中的像素
void ImageDeal::TransPix()
{

	Mat m_TempImg = m_SrcImg.clone();

	int rowsNumber = m_TempImg.rows;
	int colsNumber = m_TempImg.cols;

	

	for (int p = 0; p < targetNum; p++)
	{
	//int p = 8;
		

		//cout << imageData[p][0] - imageData[p][6] << endl;

		double widh_k = (imageData[p][3] - imageData[p][1]) / (imageData[p][2] - imageData[p][0]);
		double high_k = (imageData[p][7] - imageData[p][1]) / (imageData[p][6] - imageData[p][0]);

		double x1 = imageData[p][0], y1 = imageData[p][1], x2 = imageData[p][2], y2 = imageData[p][3],
			x3 = imageData[p][4], y3 = imageData[p][5], x4 = imageData[p][6], y4 = imageData[p][7],
			x = 600, y = 30;
			//x = imageData[p][9], y = imageData[p][10];
		/*Point center;
		center.x = x;
		center.y = y;
		circle(m_TempImg, center, 5, Scalar(0, 255, 255), -1);
		*/
		Point start(x1, y1), end(x2, y2);
		Point start1(x1, y1), end1(x3, y3);
		line(m_TempImg, start, end, Scalar(255, 255, 0), 2, 8);
		line(m_TempImg, start1, end1, Scalar(255, 0, 255), 2, 8);
		/*
		Point start2(x2, y2), end2(x3, y3);
		Point start3(x3, y3), end3(x4, y4);
		line(m_TempImg, start2, end2, Scalar(255, 255, 255), 1, 8);
		line(m_TempImg, start3, end3, Scalar(0, 255, 255), 1, 8);
		*/
		
		int value_dis_widh = 0, value_dis_high = 0;
		double x1_next = x1 + value_dis_widh, y1_next = y1 + value_dis_widh;

		//根据车的形状，一排排赋值坐标点
			while (x1_next > x4)
			{
				//计算下一排的起始坐标和结束坐标
				x1_next = x1 + value_dis_high;
				y1_next = y1 + abs(value_dis_high*high_k);
				x2 += value_dis_high;
				x = 30;
				value_dis_widh = 0;

				while (x1_next < x2 + 1)
				{
					//计算一排内，下一个坐标点位置
					//x1_next += value_dis_widh;
					y1_next += abs(widh_k * value_dis_widh);
					//将当前点的像素值赋给目标区域坐标点,x,y表示目标区域坐标点
					int tempSwap[3] = { 0 };
					for (int i = 0; i < 3; i++)
					{
						tempSwap[i] = m_TempImg.at<Vec3b>(x, y)[i];
						m_TempImg.at<Vec3b>(x, y)[i] = m_TempImg.at<Vec3b>(x1_next, y1_next)[i];
						m_TempImg.at<Vec3b>(x1_next, y1_next)[i] = 0;
					}
					Point center;
					center.x = x1_next;
					center.y = y1_next;
					circle(m_TempImg, center, 0.5, Scalar(255, 255, 0), -1);

					x++;
					value_dis_widh++;
					x1_next++;
				}
				y++;
				//if (flag_direction)
				//{
					value_dis_high--;
					//x1_next--;
				//}
				//else
				//{
				//	value_dis_high++;
				//	x1_next++;
				//}
			}
		
		
	}
	imshow("before", m_SrcImg);
	imshow("after", m_TempImg);

	waitKey();

}


void ImageDeal::run()
{
	/*string temp;
	int num=0, i=0, k=1888;
	while(num < fileNumber)
	{
		myUtil->int_str(i, temp, NOFORMAT, 0);
		myUtil->ChangeName(file_fullName_src, temp, imageType_src);
		myUtil->ChangePath(filePath, fullPath_src, file_fullName_src);
		if(myUtil->ReadImage(fullPath_src, m_ResImg))
		{
			//k++;
			num++;
			myUtil->int_str(i, temp, HAVEFORMAT, nameLength);
			myUtil->ChangeName(file_fullName_des, temp, imageType_des);
			myUtil->ChangePath(filePath + "../", fullPath_des, file_fullName_des);
			myUtil->WriteImage(fullPath_des, m_ResImg);
			
		}
		i++;
	}*/

	
	for (int i = 0; i < fileNumber; i++)
	{
		//图片批处理锐化，旋转操作
		if(ReadImage(i))
        {
            TransImage("SHARPEN");
            if (m_ResImg.data)
                WriteToFile("../tanke/", "SHARPEN", -1);
            TransImage("ROTATE");
            if (imageList_des.size() > 0)
            {
                for (int j = 1; j < imageList_des.size() + 1; j++)
                {

                    WriteToFile("../tanke/", "ROTATE", j);
                }
                imageList_des.clear();
            }
        }


		//TransPix();
	}
}


