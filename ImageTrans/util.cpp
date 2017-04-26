#include <fstream>

#include "util.h"
#include <iomanip>


MyUtil::MyUtil()
{
	
}

void MyUtil::ReadText(vector<double> &data_v, string path)
{
	fstream fileIn;
	fileIn.open(path, ios::in);
	if (fileIn.is_open())
	{
		int k = 0;
		double temp = 0;

		while (!fileIn.eof())
		{
			fileIn>> temp;
			data_v.push_back(temp);
		}
		fileIn.close();
	}


}

/*
//��ȡtext�����ļ������������ݵĸ�������Ҫ��,���� �任ǰ��ͼƬ�����������
int ImageDeal::ReadText(string path)
{
fstream in, out;
float buf[3000];
char tmp[200];

//�򿪱�ǩ�����ļ�
in.open(path, ios::in);

//����ǩ�����ļ������ڴ�
int cnt = 0;
while (!in.eof()) {
in >> buf[cnt];
cnt++;
}

in.close();

//��ÿ����ǩ���������
int car_num = (cnt - 1) / 13, n = 0;
for (int i = 0; i < car_num; i++) {
for (int j = 0; j < 13; j++) {
imageData[i][j] = (int)buf[n];
n++;
}
}
n = 0;

for (int i = 0; i < car_num; i++) {
if (imageData[i][9] <= 0) {
imageData[i][9] = 3;
}
else if (imageData[i][10] <= 0) {
imageData[i][10] = 3;
}
//		else if ((num[i][9] + num[i][11]) <= 0) {
//			num[i][9] + num[i][11] = 3;
//		}
//		else if ((num[i][10] + num[i][12]) <= 0)
//			num[i][10] + num[i][12] = 3;
//		}
}

return car_num;
}
*/

//��ȡ·���µ�ͼƬ��Ҫ���ṩ��ȡͼƬ��·������������ʽ
bool MyUtil::ReadImage(const string &path, Mat &m_temp)
{
	m_temp = imread(path);
	if (!m_temp.data)
		return false;
	return true;

}

//��һ����ʽдͼƬ���ļ�ϵͳ
void MyUtil::WriteImage(string &desPath, Mat &m_desImage)
{
	
	imwrite(desPath, m_desImage);
}

//��ͼƬд���µ�·��ȥ
void MyUtil::ChangePath(string &oldPath, string &newPath, string &fileName)
{
	newPath = oldPath + fileName;
}

//��formatΪ��ʽ��000012����indexΪ��һ����ţ�12����type��ʾ���������
void MyUtil::ChangeName(string &fullName_des, const string &name_src, const string &type)
{
	fullName_des = name_src + "." + type;
}


//int ת���� string
void MyUtil::int_str(int &int_temp, string &string_temp, int type, int nameLength)
{
	stringstream stream;
	if (type == haveFormat) //int to string
	{
		stream.str("");
		stream << setfill('0') << setw(nameLength) << int_temp;
		string_temp = stream.str();   //�˴�Ҳ������ stream>>string_temp  

	}
	if (type == noFormat) //int to string
	{
		stream.str("");
		stream << int_temp;
		string_temp = stream.str();   //�˴�Ҳ������ stream>>string_temp  ������ͼƬ��������䳤

	}
	else
	{
		stream.str("");
		stream << string_temp;
		stream >> int_temp;

	}

}

