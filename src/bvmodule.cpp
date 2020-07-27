#include"bvmodule.hpp"

namespace bv
{

  void save(Mat &im)
  {
    /*Mat im_th;

    // Binarize the image by thresholding
    threshold(im, im_th, 128, 255, THRESH_BINARY);
    // Flood fill
    Mat im_floodfill = im_th.clone();
    floodFill(im_floodfill, cv::Point(0,0), Scalar(255));

    // Invert floodfilled image
    Mat im_floodfill_inv;
    bitwise_not(im_floodfill, im_floodfill_inv);

    // Combine the two images to fill holes
    im = (im_th | im_floodfill_inv);*/
    imwrite("test.jpg", im);

  }


  SF6ANTISPOOF::SF6ANTISPOOF(float clarity, float reality) 
  {
	//std::string gmodelpath = "models//";
	std::string gmodelpath = "/workspace/autohome/project/faceAntiSpoof_PYWARP/models//";
	seeta::ModelSetting spoof_model;
	spoof_model.append(gmodelpath + "fas_first.csta"); //局部模型
	spoof_model.append(gmodelpath + "fas_second.csta"); //全局模型
	spoof_model.set_device( seeta::ModelSetting::CPU );
	//spoof_model.set_device( seeta::ModelSetting::GPU ); //Compute device gpu has no memory device registered. Please call RegisterMemoryDevice firstly
	spoof_model.set_id(0);
	
	m_spoof = new seeta::FaceAntiSpoofing(spoof_model);  //FaceAntiSpoofing孾Z举I作¨FaceAntiSpoofing.h中
	m_spoof->SetThreshold(clarity, reality); //clarity = 0.3, reality=0.01

  }


  //predictrst SF6ANTISPOOF::predict(Mat mat) 
  bool SF6ANTISPOOF::predict(Mat mat) 
  {
  
	m_image.height = mat.rows;
	m_image.width = mat.cols;
	m_image.channels = mat.channels();
	m_image.data = mat.data;//图片数据
	
	m_facePos.x = mat.rows/2 - 35;
    m_facePos.y = mat.cols/2 - 40;
    m_facePos.width = 70;
    m_facePos.height = 80;

    m_sf_pt.x=mat.rows/2 - 25;
    m_sf_pt.y=mat.cols/2 - 30;
    m_sf_pts.push_back(m_sf_pt);
    m_sf_pt.x=mat.rows/2 + 25;
    m_sf_pt.y=mat.cols/2 - 30;
    m_sf_pts.push_back(m_sf_pt);
    m_sf_pt.x=mat.rows/2;
    m_sf_pt.y=mat.cols/2;
    m_sf_pts.push_back(m_sf_pt);
    m_sf_pt.x=mat.rows/2 - 15;
    m_sf_pt.y=mat.cols/2 + 25;
    m_sf_pts.push_back(m_sf_pt);
    m_sf_pt.x=mat.rows/2 + 15;
    m_sf_pt.y=mat.cols/2 + 25;
    m_sf_pts.push_back(m_sf_pt);

	float clarity, reality;
	
	auto status = m_spoof->Predict( m_image, m_facePos, m_sf_pts.data() );
	m_spoof->GetPreFrameScore(&clarity, &reality);
	auto is_real = status != seeta::FaceAntiSpoofing::REAL;

	predictrst rst;
	rst.clarity = clarity;
	rst.reality = reality;
	rst.is_real = is_real;
	//return rst;
	return is_real;
  }

}

