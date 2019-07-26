#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;


int main(int argc, const char *argv[])
{
	// 输入参数 待整理
	char *Path;
	if (argc >= 2) {
		Path = const_cast<char*>(argv[1]);
		cout << "run at modify 1" << endl;
	}
	else {
		Path = "./data_p_qut2.csv";
		cout << "run at default" << endl;
	}

	system("pause");

	return 0;
}