#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "histogram.h"

int main()
{
	// Read input image
	cv::Mat image = cv::imread("C:\\Users\\User\\Desktop\\sunflower.jpg", 0);	// read as gray level image
	if (!image.data)
		return 0;

	// save grayscale image
	cv::imwrite("groupBW.bmp", image);

	// Display the image
	cv::namedWindow("Image");
	cv::imshow("Image", image);

	// The histogram object
	Histogram1D h;

	// Compute the histogram
	cv::Mat histo = h.getHistogram(image);

	// Loop over each bin
	for (int i = 0; i < 256; i++)
		cout << "Value " << i << " = " << histo.at<float>(i) << endl;

	// Display a histogram as an image
	cv::namedWindow("Histogram");
	cv::imshow("Histogram", h.getHistogramImage(image));

	// re-display the histagram with chosen threshold indicated
	cv::Mat hi = h.getHistogramImage(image);
	cv::line(hi, cv::Point(70, 0), cv::Point(70, 255), cv::Scalar(128));
	cv::namedWindow("Histogram with threshold value");
	cv::imshow("Histogram with threshold value", hi);

	// creating a binary image by thresholding at the valley
	cv::Mat thresholded; // output binary image
	cv::threshold(image, thresholded,
		70,    // threshold value
		255,   // value assigned to pixels over threshold value
		cv::THRESH_BINARY); // thresholding type

// Display the thresholded image
	cv::namedWindow("Binary Image");
	cv::imshow("Binary Image", thresholded);
	thresholded = 255 - thresholded;
	cv::imwrite("binary.bmp", thresholded);

	// Equalize the image
	cv::Mat eq = h.equalize(image);

	// Show the result
	cv::namedWindow("Equalized Image");
	cv::imshow("Equalized Image", eq);

	// Show the new histogram
	cv::namedWindow("Equalized H");
	cv::imshow("Equalized H", h.getHistogramImage(eq));

	// Stretch the image, setting the 1% of pixels at black and 1% at white
	cv::Mat str1 = h.stretch1(image, 0.01f);									// choose Stretch1

	// Show the result
	cv::namedWindow("Stretched1 Image");										// change nameWindow
	cv::imshow("Stretched1 Image", str1);										// show Stretch1 result

	// Show the new histogram
	cv::namedWindow("Stretched1 H");											// change nameWindow
	cv::imshow("Stretched1 H", h.getHistogramImage(str1));						// show Stretch1 result

	cv::Mat str2 = h.stretch2(image, 0.01f);									// choose Stretch2

	// Show the result
	cv::namedWindow("Stretched2 Image");										// change nameWindow
	cv::imshow("Stretched2 Image", str2);										// show Stretch2 result

	// Show the new histogram
	cv::namedWindow("Stretched2 H");											// change nameWindow
	cv::imshow("Stretched2 H", h.getHistogramImage(str2));						// show Stretch2 result


	// Create an image inversion table
	cv::Mat lut(1, 256, CV_8U); // 1x256 matrix

	// Or:
	// int dim(256);
	// cv::Mat lut(1,  // 1 dimension
	// 	&dim,          // 256 entries
	//	CV_8U);        // uchar

	for (int i = 0; i < 256; i++) {

		// 0 becomes 255, 1 becomes 254, etc.
		lut.at<uchar>(i) = 255 - i;												// 0 becomes 255, 255 becomes 0
	}

	// Apply lookup and display negative image
	cv::namedWindow("Negative image");
	cv::imshow("Negative image", h.applyLookUp(image, lut));

	cv::waitKey();
	return 0;
}
