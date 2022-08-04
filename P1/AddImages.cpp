#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <iomanip>

int main()
{
	cv::Mat image1;
	cv::Mat image2;

	// open images
	image1 = cv::imread("moon2.jpg");
	image2 = cv::imread("aurora.jpg");
	if (!image1.data)
		return 0;
	if (!image2.data)
		return 0;

	cv::namedWindow("Image 1");
	cv::imshow("Image 1", image1);
	cv::namedWindow("Image 2");
	cv::imshow("Image 2", image2);

	cv::Mat result;
	// add two images
	cv::addWeighted(image1, 1, image2, 0.1, 0., result);

	cv::namedWindow("result");
	cv::imshow("result", result);

	//cv::imwrite("./resultaaa.bmp", result);								// imwrite

	// using overloaded operator
	result = 0.7 * image1 + 0.9 * image2;

	cv::namedWindow("result with operators");
	cv::imshow("result with operators", result);

	//cv::imwrite("./resultwithoperatorsaaa.bmp", result);					// imwrite

	image2 = cv::imread("aurora.jpg", 0);			// read as gray scale image 


	// create vector of 3 images
	std::vector<cv::Mat> planes;
	// split 1 3-channel image into 3 1-channel images
	cv::split(image1, planes);
	// add to red channel
	planes[0] += image2;

	cv::namedWindow("Plane 0");
	cv::imshow("Plane 0", planes[0]);										// show planes[0] image

	std::cout << "planes[0].size() = " << planes[0].size() << std::endl;	// planes[0].size()

	// merge the 3 1-channel images into 1 3-channel image
	cv::merge(planes, result);

	cv::namedWindow("Result on blue channel");
	cv::imshow("Result on blue channel", result);

	//cv::imwrite("./resultonbluechannel.bmp", result);					// imwrite

	cv::waitKey();

	return 0;
}
