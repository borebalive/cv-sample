/*
1.KNN
2.MOG2
*/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

//#include "background_segm.hpp"
//#include "bgsegm.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char *argv[])
{
	/// ����ģ��
	Ptr<BackgroundSubtractorMOG2> bg_model = createBackgroundSubtractorMOG2();
	//createBackgroundSubtractorKNN

	/// ����ģ�Ͳ���
	bg_model->setHistory(500);
	//bg_model->setNMixtures(5);
	//bg_model->setBackgroundRatio(1);
	bg_model->setVarThreshold(16.0);
	//bg_model->setVarThresholdGen
	//setVarInit // ��˹ģ�ͷ����ʼֵ 15
	//setVarMin // ��˹ģ�ͷ�����Сֵ 4
	//setVarMax // ��˹ģ�ͷ������ֵ 75
	//setComplexityReductionThreshold
	bg_model->setDetectShadows(true);
	bg_model->setShadowValue(127);
	//setShadowThreshold

	/// ��ȡѵ����Ƶ
	/*
	VideoCapture cap;
	cap.open("1.avi"); // ·��

	if (!cap.isOpened())
	{
		cout << "Can not open video file." << endl;
		return -1;
	}
	*/
	Mat input_frame, output_frame, bgmask;

	string inputName = "D:\\img\\1.jpg";
	input_frame = imread(inputName);

	//cap >> input_frame;

	if (input_frame.empty())
	{
		cout << "Can not read data from the video source." << endl;
		return -1;
	}

	/// ѵ��ģ��
	for (int i=0;i<1000;i++)
	{
		bg_model->apply(input_frame, bgmask, -1); // 0�����£�1����������֡���£�-1�Զ������ʡ�

		//refineSegments(tmp_frame, bgmask, out_frame);
	}

	/// չʾģ��
	//getBackgroundImage

	/// ����ģ��
	/*
	FileStorage fs("bg_model.yml", FileStorage::WRITE);
	//bg_model->write(fs);
	fs << "model" << bg_model;
	*/
	bg_model->save("bg_model.xml");

	/// ��ȡģ��
	//bg_model->read();
	//FileStorage fsRead("bg_model.yml", FileStorage::READ);
	//Ptr<BackgroundSubtractorMOG2> mog2 = Algorithm::read<BackgroundSubtractorMOG2>(fsRead.root());

	system("pause");

 	return 0;
}
