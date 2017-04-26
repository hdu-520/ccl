#ifndef __UTIL_H__ 
#define __UTIL_H__ 


#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class MyUtil
{
public:
	MyUtil();
	void ReadText(vector<double> &data, string path);

	//读取路径下的图片，要求提供读取图片的路径，数量，格式
	bool ReadImage(const string &path, Mat &m_temp);
	
	//以一定格式写图片到文件系统
	void WriteImage(string &desPath, Mat &m_desImage);

	//把图片写到新的路径去
	void ChangePath(string &oldPath, string &newPath, string &fileName);

	//以format为格式（000012），index为第一个编号，12，，type表示保存的类型
	void ChangeName(string &fullName_des, const string &name_src, const string &type);

	//int 转换成 string
	void int_str(int &int_temp, string &string_temp, int type, int nameLength);

    void AlterXML(double data[][4], string path);


private:
	const int haveFormat = 1;
	const int noFormat = 2;


};







#endif
