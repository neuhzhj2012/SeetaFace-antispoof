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
        std::string gmodelpath = "models//";
        seeta::ModelSetting spoof_model;
        spoof_model.append(gmodelpath + "fas_first.csta"); //局部模型
        spoof_model.append(gmodelpath + "fas_second.csta"); //全局模型
        spoof_model.set_device( seeta::ModelSetting::CPU );
        //spoof_model.set_device( seeta::ModelSetting::GPU ); //Compute device gpu has no memory device registered. Please call RegisterMemoryDevice firstly
        spoof_model.set_id(0);
        seeta::FaceAntiSpoofing * m_spoof;
        m_spoof = new seeta::FaceAntiSpoofing(spoof_model);  //FaceAntiSpoofing孾Z举I作¨FaceAntiSpoofing.h中
        //m_spoof->SetThreshold(0.30, 0.80);
        m_spoof->SetThreshold(0.30, 0.01);

        SeetaImageData image;
        SeetaRect facePos;
        std::vector<SeetaPointF> points;
        SeetaPointF tmp;


        std::vector<cv::String> filenames;
        cv::String folder = argv[1];

        cv::glob(folder, filenames);
        cout <<folder<<"num: "<<filenames.size()<<filenames[0]<<endl;
	cv::Mat mat, mat2;
        //for (int i; i < filenames.size(); i++)
        int i = filenames.size();
        while(--i)
        {
        cv::String imgpath = filenames[i]; 
        cout<<imgpath<<endl;
        mat = cv::imread(imgpath);

        //cv::Size size (400, 400);  //归一化
        //cv::resize(mat, mat2, size, 0, 0, cv::INTER_CUBIC);
        //mat = mat2.clone();

	//数据转换为SeetaImageData
	image.height = mat.rows;
	image.width = mat.cols;
	image.channels = mat.channels();
	image.data = mat.data;

        /*
	facePos.x = 115;
	facePos.y = 115;
	facePos.width = 30;
	facePos.height = 45;

	tmp.x=127;
	tmp.y=120;
	points.push_back(tmp);
	tmp.x=140;
	tmp.y=120;
	points.push_back(tmp);
        tmp.x=130;
        tmp.y=135;
        points.push_back(tmp);
        tmp.x=128;
        tmp.y=145;
        points.push_back(tmp);
        tmp.x=135;
        tmp.y=146;
        points.push_back(tmp);
	*/ 
        facePos.x = mat.rows/2 - 35;
        facePos.y = mat.cols/2 - 40;
        facePos.width = 70;
        facePos.height = 80;

        tmp.x=mat.rows/2 - 25;
        tmp.y=mat.cols/2 - 30;
        points.push_back(tmp);
        tmp.x=mat.rows/2 + 25;
        tmp.y=mat.cols/2 - 30;
        points.push_back(tmp);
        tmp.x=mat.rows/2;
        tmp.y=mat.cols/2;
        points.push_back(tmp);
        tmp.x=mat.rows/2 - 15;
        tmp.y=mat.cols/2 + 25;
        points.push_back(tmp);
        tmp.x=mat.rows/2 + 15;
        tmp.y=mat.cols/2 + 25;
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
        points.push_back(tmp); */ //77.04% self_AI_all
	//活体检测 Predict( const SeetaImageData &image, const SeetaRect &face, const SeetaPointF *points ) const;
	auto status = m_spoof->Predict( image, facePos, points.data() );

	float clarity;
	float reality;
 	m_spoof->GetPreFrameScore(&clarity, &reality);

	cout << "Clarity = " << clarity << ", Reality = " << reality << endl;

	cout <<status<<endl;
	//if( status != seeta::FaceAntiSpoofing::REAL)
	if( reality<0.01)
	{
		cout<< "antispoofing check failed!"<<endl;
		//return -2;
	}
       }
}





