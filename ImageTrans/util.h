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

	//��ȡ·���µ�ͼƬ��Ҫ���ṩ��ȡͼƬ��·������������ʽ
	bool ReadImage(const string &path, Mat &m_temp);
	
	//��һ����ʽдͼƬ���ļ�ϵͳ
	void WriteImage(string &desPath, Mat &m_desImage);

	//��ͼƬд���µ�·��ȥ
	void ChangePath(string &oldPath, string &newPath, string &fileName);

	//��formatΪ��ʽ��000012����indexΪ��һ����ţ�12����type��ʾ���������
	void ChangeName(string &fullName_des, const string &name_src, const string &type);

	//int ת���� string
	void int_str(int &int_temp, string &string_temp, int type, int nameLength);

    void AlterXML(double data[][4], string path);


private:
	const int haveFormat = 1;
	const int noFormat = 2;


};







#endif
