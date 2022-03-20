#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "imageComparator.h"

int main()
{
	// Read reference image
	cv::Mat image = cv::imread("C:\\Users\\User\\Desktop\\sunflower.jpg");			// read as gray level image
	if (!image.data)
		return 0;

	// Display image
	cv::namedWindow("Query Image");
	cv::imshow("Query Image", image);

	ImageComparator c;
	c.setReferenceImage(image);

	// Read an image and compare it with reference
	cv::Mat input = cv::imread("C:\\Users\\User\\Desktop\\moon1.jpg");				// read image
	cout << "sunflower vs moon1: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\moon2.jpg");						// read image
	cout << "sunflower vs moon2: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\aurora.jpg");						// read image
	cout << "sunflower vs aurora: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\rabit.jpg");						// read image
	cout << "sunflower vs rabit: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\sunflower1.jpg");					// read image
	cout << "sunflower vs sunflower1: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\sunflower2.jpg");					// read image
	cout << "sunflower vs sunflower2: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\sunflower3.jpg");					// read image
	cout << "sunflower vs sunflower3: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\sunflower4.jpg");					// read image
	cout << "sunflower vs sunflower4: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("C:\\Users\\User\\Desktop\\sunflower.jpg");					// read image
	cout << "sunflower vs sunflower: " << c.compare(input) << endl;

	cv::waitKey();
	return 0;
}
