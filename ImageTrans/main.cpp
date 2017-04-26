#define _CRT_SECURE_NO_WARNINGS

#include "imageDeal.h"
#include "util.h"
/*
 * 这个项目本来是在vs2015写的，所以存在编码问题，打开的时候中文注释可能会没有，所以需要以gbk-2312格式重新打开每个cpp即可
 *
 * 封装了一个实现图片处理和锐化的功能，可以批量修改文件名，可能要自己修改一下
 *
 */
#include <experimental/filesystem>
using namespace std::experimental::filesystem::v1;

int main()
{
	/*path p("d:\\");
	directory_iterator iter(p), _end;
	while (iter != _end){
		cout << (iter++)->path() << endl;
	}*/
	//vector<double > v;

	//Mat m = imread("D:/CAR/sharpen/000001_s.jpg");
	//Mat_<Vec3b>::iterator it = m.begin<Vec3b>();
	//Mat_<Vec3b>::iterator itend = m.end<Vec3b>();
	//int rowsNumber = m.rows;
	//int colsNumber = m.cols*m.channels();
	//for (int i = 0; i < 10; i++)
	//{

	//	cout << it[i] << endl;;
	//
	//	/*uchar* d = m.ptr<uchar>(i);
	//	for (int j = 0; j < 10; j++)
	//		cout << d[j] << endl;*/

	//}

	//getchar();






	ImageDeal myImageDeal("/home/chen/Desktop/tanke_all/image/", "000001", "jpg", 3000);

	myImageDeal.run();



	return 0;
}