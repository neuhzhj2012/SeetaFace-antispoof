//#include "Struct.h"
//#include "CStruct.h" //ModelSetting,SeetaImageData 结构体定义头文件
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "FaceAntiSpoofing.h" //FaceAntiSpoofing  头文件

using namespace std;
using namespace cv;




int main(int argc, char * argv [ ])
{
	std::string imgpath=argv[1];
	cv::Mat mat, mat2;
        mat = cv::imread(imgpath);

        cv::Size size (400, 400);  //归一化
        cv::resize(mat, mat2, size, 0, 0, cv::INTER_CUBIC);
        mat = mat2.clone();

	//数据转换为SeetaImageData
	SeetaImageData image; 
	image.height = mat.rows;
	image.width = mat.cols;
	image.channels = mat.channels();
	image.data = mat.data;

	
	//模型初始化
	std::string gmodelpath = "models//";
	seeta::ModelSetting spoof_model;  
	spoof_model.append(gmodelpath + "fas_first.csta");
	spoof_model.append(gmodelpath + "fas_second.csta");
	spoof_model.set_device( seeta::ModelSetting::CPU );
	spoof_model.set_id(0);
        seeta::FaceAntiSpoofing * m_spoof;
	m_spoof = new seeta::FaceAntiSpoofing(spoof_model);  //FaceAntiSpoofing定义在FaceAntiSpoofing.h中
	m_spoof->SetThreshold(0.30, 0.80);

	//人脸位置和特征点参数
	SeetaRect facePos;
	std::vector<SeetaPointF> points;


	facePos.x = 115;
	facePos.y = 35;
	facePos.width = 187;
	facePos.height = 175;

        SeetaPointF tmp;
	tmp.x=152;
	tmp.y=97;
	points.push_back(tmp);
	tmp.x=254;
	tmp.y=95;
	points.push_back(tmp);
        tmp.x=202;
        tmp.y=136;
        points.push_back(tmp);
        tmp.x=161;
        tmp.y=175;
        points.push_back(tmp);
        tmp.x=241;
        tmp.y=173;
        points.push_back(tmp);
	
	/*
        facePos.x = 453;
        facePos.y = 107;
        facePos.width = 164;
        facePos.height = 250;

        SeetaPointF tmp;
        tmp.x=475;
        tmp.y=198;
        points.push_back(tmp);
        tmp.x=579;
        tmp.y=218;
        points.push_back(tmp);
        tmp.x=523;
        tmp.y=282;
        points.push_back(tmp);
        tmp.x=483;
        tmp.y=314;
        points.push_back(tmp);
        tmp.x=551;
        tmp.y=322;
        points.push_back(tmp); */
	//活体检测 Predict( const SeetaImageData &image, const SeetaRect &face, const SeetaPointF *points ) const;
	auto status = m_spoof->Predict( image, facePos, points.data() );

	float clarity;
	float reality;
 	m_spoof->GetPreFrameScore(&clarity, &reality);

	cout << "Clarity = " << clarity << ", Reality = " << reality << endl;

	cout <<status<<endl;
	if( status != seeta::FaceAntiSpoofing::REAL)
	{
		cout<< "antispoofing check failed!";
		return -2;
	}
}





