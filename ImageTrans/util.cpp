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
//读取text数据文件，并返回数据的个数（按要求）,放入 变换前的图片特征点的数据
int ImageDeal::ReadText(string path)
{
fstream in, out;
float buf[3000];
char tmp[200];

//打开标签数据文件
in.open(path, ios::in);

//将标签数据文件读入内存
int cnt = 0;
while (!in.eof()) {
in >> buf[cnt];
cnt++;
}

in.close();

//将每个标签点存入数组
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

//读取路径下的图片，要求提供读取图片的路径，数量，格式
bool MyUtil::ReadImage(const string &path, Mat &m_temp)
{
	m_temp = imread(path);
	if (!m_temp.data)
		return false;
	return true;

}

//以一定格式写图片到文件系统
void MyUtil::WriteImage(string &desPath, Mat &m_desImage)
{
	
	imwrite(desPath, m_desImage);
}

//把图片写到新的路径去
void MyUtil::ChangePath(string &oldPath, string &newPath, string &fileName)
{
	newPath = oldPath + fileName;
}

//以format为格式（000012），index为第一个编号，12，，type表示保存的类型
void MyUtil::ChangeName(string &fullName_des, const string &name_src, const string &type)
{
	fullName_des = name_src + "." + type;
}


//int 转换成 string
void MyUtil::int_str(int &int_temp, string &string_temp, int type, int nameLength)
{
	stringstream stream;
	if (type == haveFormat) //int to string
	{
		stream.str("");
		stream << setfill('0') << setw(nameLength) << int_temp;
		string_temp = stream.str();   //此处也可以用 stream>>string_temp  

	}
	if (type == noFormat) //int to string
	{
		stream.str("");
		stream << int_temp;
		string_temp = stream.str();   //此处也可以用 stream>>string_temp  ，不把图片名子扩充变长

	}
	else
	{
		stream.str("");
		stream << string_temp;
		stream >> int_temp;

	}

}

