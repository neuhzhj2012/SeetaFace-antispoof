#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "FaceAntiSpoofing.h" //FaceAntiSpoofing  头文件

using namespace std;
using namespace cv;

namespace bv
{

	CV_EXPORTS_W void save(Mat &mat);
        CV_EXPORTS_W struct predictrst{
                        float clarity; //清晰度
                        float reality; //真实性
                        bool is_real; //当前图片的判断结果
                        };

	class CV_EXPORTS_W SF6ANTISPOOF 
	{

	private:
		seeta::FaceAntiSpoofing * m_spoof;
		SeetaImageData m_image;
        SeetaRect m_facePos;
        std::vector<SeetaPointF> m_sf_pts;
        SeetaPointF m_sf_pt;

		
	public:
		/*CV_WRAP struct predictrst{
			float clarity; //清晰度
			float reality; //真实性
			bool is_real; //当前图片的判断结果
			};*/
		CV_WRAP  SF6ANTISPOOF(float clarity=0.3, float reality=0.01); 
		//CV_WRAP predictrst predict(Mat im); //预测当前图像的真实性 
		CV_WRAP bool predict(Mat im); //预测当前图像的真实性 
		//CV_WRAP getscore(float &clarity, float &reality); //清晰度和真实性，先执行predict才能执行该函数活动对应的分值

	};
}
