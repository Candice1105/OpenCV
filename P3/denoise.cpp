#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main()
{
	// Read as gray level image
	cv::Mat image = cv::imread("C:\\Users\\User\\Desktop\\aurora.jpg", 0);
	if (!image.data)
		return 0;

	// Display the original image
	cv::namedWindow("Original image");
	cv::imshow("Original image", image);

	cv::Mat result;
	// Blur the image (mean filter 5x5)						// Mean
	cv::blur(image, result, cv::Size(5, 5));

	// Display mean filtered Image (5x5)
	cv::namedWindow("Mean filtered image (5x5)");
	cv::imshow("Mean filtered image (5x5)", result);

	// Blur the image (mean filter 9x9)
	cv::blur(image, result, cv::Size(9, 9));

	// Display mean filtered Image (9x9)
	cv::namedWindow("Mean filtered image (9x9)");
	cv::imshow("Mean filtered image (9x9)", result);

	// Blur the image (mean filter 13x13)
	cv::blur(image, result, cv::Size(13, 13));

	// Display mean filtered Image (13x13)
	cv::namedWindow("Mean filtered image (13x13)");
	cv::imshow("Mean filtered image (13x13)", result);

	// Blur the image (Gaussian filter 5x5)						// Gaussian sigma = 1
	cv::GaussianBlur(image, result,cv::Size(5, 5), 1, 1);

	// Display Gaussian filtered Image (5x5)
	cv::namedWindow("Gaussian filtered image (5x5)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("Gaussian filtered image (5x5)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the image (Gaussian filter 9x9)
	cv::GaussianBlur(image, result, cv::Size(9, 9), 1, 1);

	// Display Gaussian filtered Image (9x9)
	cv::namedWindow("Gaussian filtered image (9x9)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("Gaussian filtered image (9x9)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the image (Gaussian filter 13x13)
	cv::GaussianBlur(image, result, cv::Size(13, 13), 1, 1);

	// Display Gaussian filtered Image (13x13)
	cv::namedWindow("Gaussian filtered image (13x13)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("Gaussian filtered image (13x13)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the image (Gaussian filter 5x5)(sigmaX = 2, sigmaY = 2)			// Gaussian sigma = 2
	cv::GaussianBlur(image, result, cv::Size(5, 5), 2, 2);

	// Display Gaussian filtered Image (5x5)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("Gaussian filtered image (5x5)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("Gaussian filtered image (5x5)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the image (Gaussian filter 9x9)(sigmaX = 2, sigmaY = 2)
	cv::GaussianBlur(image, result, cv::Size(9, 9), 2, 2);

	// Display Gaussian filtered Image (9x9)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("Gaussian filtered image (9x9)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("Gaussian filtered image (9x9)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the image (Gaussian filter 13x13)(sigmaX = 2, sigmaY = 2)
	cv::GaussianBlur(image, result, cv::Size(13, 13), 2, 2);

	// Display Gaussian filtered Image (13x13)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("Gaussian filtered image (13x13)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("Gaussian filtered image (13x13)(sigmaX = 2, sigmaY = 2)", result);

	// Read as gray level image (Salt&Pepper)									////////////////
	image = cv::imread("C:\\Users\\User\\Desktop\\aurora_salt6000.bmp", 0);
	if (!image.data)
		return 0;

	// Display the S&P original image
	cv::namedWindow("S&P image");
	cv::imshow("S&P image", image);

	// Blur the S&P image (mean filter 5x5)
	cv::blur(image, result, cv::Size(5, 5));

	// Display S&P mean filtered image (5x5)
	cv::namedWindow("S&P mean filtered image (5x5)");
	cv::imshow("S&P mean filtered image (5x5)", result);

	// Blur the S&P image (mean filter 9x9)
	cv::blur(image, result, cv::Size(9, 9));

	// Display S&P mean filtered image (9x9)
	cv::namedWindow("S&P mean filtered image (9x9)");
	cv::imshow("S&P mean filtered image (9x9)", result);

	// Blur the S&P image (mean filter 13x13)
	cv::blur(image, result, cv::Size(13, 13));

	// Display S&P mean filtered image (13x13)
	cv::namedWindow("S&P mean filtered image (13x13)");
	cv::imshow("S&P mean filtered image (13x13)", result);

	// Applying a median filter											///////////////////
	cv::medianBlur(image, result, 5);

	// Display the blurred image
	cv::namedWindow("Median filtered Image");
	cv::imshow("Median filtered Image", result);									///////////////////





	cv::waitKey();
	return 0;
}
