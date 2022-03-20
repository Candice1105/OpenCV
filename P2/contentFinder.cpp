#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "histogram.h"
#include "contentFinder.h"
#include "colorhistogram.h"

int main()
{
	// Read input image
	cv::Mat image = cv::imread("C:\\Users\\User\\Desktop\\sunflower.jpg", 0);		// read as gray level image
	if (!image.data)
		return 0;

	// define image ROI
	cv::Mat imageROI;
	imageROI = image(cv::Rect(216, 33, 24, 30));						            // Cloud region

	// Display reference patch
	cv::namedWindow("Reference");
	cv::imshow("Reference", imageROI);

	// Find histogram of reference
	Histogram1D h;
	cv::Mat hist = h.getHistogram(imageROI);
	cv::namedWindow("Reference Hist");
	cv::imshow("Reference Hist", h.getHistogramImage(imageROI));

	// Create the content finder
	ContentFinder finder;

	// set histogram to be back-projected
	finder.setHistogram(hist);
	finder.setThreshold(0.12f);

	// Get back-projection
	cv::Mat result1;
	result1 = finder.find(image);

	// Create negative image and display result
	cv::Mat tmp;
	result1.convertTo(tmp, CV_8U, -1.0, 255.0);
	cv::namedWindow("Backprojection result");
	cv::imshow("Backprojection result", tmp);

	// Get binary back-projection
	finder.setThreshold(0.12f);														// change Threshold
	result1 = finder.find(image);

	cv::Mat image2 = cv::imread("C:\\Users\\User\\Desktop\\moon1.jpg", 0);			// read as gray level image
	cv::Mat result_2;
	result_2 = finder.find(image2);								                    // Get back-projection

	// Draw a rectangle around the reference area
	cv::rectangle(image, cv::Rect(216, 33, 24, 30), cv::Scalar(0, 0, 0));

	// Display image
	cv::namedWindow("Image");
	cv::imshow("Image", image);

	// Display result
	cv::namedWindow("Detection Result (1)");						                // change nameWindow
	cv::imshow("Detection Result (1)", result1);						            // display result

	// Display result
	cv::namedWindow("Detection Result (2)");						                // change nameWindow
	cv::imshow("Detection Result (2)", result_2);									// display result

	// Load color image
	ColorHistogram hc;
	cv::Mat color = cv::imread("C:\\Users\\User\\Desktop\\sunflower.jpg");			// read image

	// extract region of interest
	imageROI = color(cv::Rect(0, 0, 100, 45));							            // blue sky area

	cv::namedWindow("First Image");
	cv::imshow("First Image", color);							                    // display First Image

	// Get 3D colour histogram (8 bins per channel)
	hc.setSize(8); // 8x8x8
	cv::Mat shist = hc.getHistogram(imageROI);

	// set histogram to be back-projected
	finder.setHistogram(shist);
	finder.setThreshold(0.05f);

	// Get back-projection of color histogram
	result1 = finder.find(color);

	cv::namedWindow("Color Detection Result (1)");						            // change nameWindow
	cv::imshow("Color Detection Result (1)", result1);								// display result

	// Second color image
	cv::Mat color2 = cv::imread("C:\\Users\\User\\Desktop\\moon1.jpg");				// read image

	cv::namedWindow("Second Image");
	cv::imshow("Second Image", color2);

	// Get back-projection of color histogram
	cv::Mat result2 = finder.find(color2);

	cv::namedWindow("Color Detection Result (2)");						            // change nameWindow
	cv::imshow("Color Detection Result (2)", result2);						        // display result

	// Get ab color histogram
	hc.setSize(256); // 256x256
	cv::Mat colorhist = hc.getabHistogram(imageROI);

	// display 2D histogram
	colorhist.convertTo(tmp, CV_8U, -1.0, 255);							            // change parameter
	cv::namedWindow("ab histogram (-1.0,255)");							            // change nameWindow
	cv::imshow("ab histogram (-1.0,255)", tmp);										// display result

	// set histogram to be back-projected
	finder.setHistogram(colorhist);
	finder.setThreshold(0.05f);

	// Convert to Lab space
	cv::Mat lab;
	cv::cvtColor(color, lab, cv::COLOR_BGR2Lab);

	// Get back-projection of ab histogram
	int ch[2] = { 1,2 };
	result1 = finder.find(lab, 0, 256.0f, ch);

	cv::namedWindow("Result ab (1)");
	cv::imshow("Result ab (1)", result1);

	// Second colour image
	cv::cvtColor(color2, lab, cv::COLOR_BGR2Lab);

	// Get back-projection of ab histogram
	result2 = finder.find(lab, 0, 256.0, ch);

	cv::namedWindow("Result ab (2)");
	cv::imshow("Result ab (2)", result2);

	// Draw a rectangle around the reference sky area
	cv::rectangle(color, cv::Rect(0, 0, 100, 45), cv::Scalar(0, 0, 0));
	cv::namedWindow("Color Image");
	cv::imshow("Color Image", color);

	// Get Hue colour histogram
	hc.setSize(180); // 180 bins
	colorhist = hc.getHueHistogram(imageROI);

	// set histogram to be back-projected
	finder.setHistogram(colorhist);

	// Convert to HSV space
	cv::Mat hsv;
	cv::cvtColor(color, hsv, cv::COLOR_BGR2HSV);

	// Get back-projection of hue histogram
	ch[0] = 0;
	result1 = finder.find(hsv, 0.0f, 180.0f, ch);

	cv::namedWindow("Result Hue (1)");
	cv::imshow("Result Hue (1)", result1);

	// Second colour image
	color2 = cv::imread("C:\\Users\\User\\Desktop\\moon1.jpg");						// read image

	// Convert to HSV space
	cv::cvtColor(color2, hsv, cv::COLOR_BGR2HSV);

	// Get back-projection of hue histogram
	result2 = finder.find(hsv, 0.0f, 180.0f, ch);

	cv::namedWindow("Result Hue (2)");
	cv::imshow("Result Hue (2)", result2);

	cv::waitKey();
	return 0;
}
