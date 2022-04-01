#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main()
{
	// Read as gray level image
	cv::Mat image = cv::imread("C:\\Users\\User\\Desktop\\sunset.jpg", 0);
	if (!image.data)
		return 0;

	// Display the original image
	cv::namedWindow("Original image");
	cv::imshow("Original image", image);

	cv::Mat result;
	// Blur the image (mean filter 3x3)								// Mean Filter
	cv::blur(image, result, cv::Size(3, 3));

	// Display mean filtered Image (3x3)
	cv::namedWindow("Mean filtered image (3x3)");
	cv::imshow("Mean filtered image (3x3)", result);
	
	// Blur the image (mean filter 5x5)
	cv::blur(image, result, cv::Size(5, 5));

	// Display mean filtered Image (5x5)
	cv::namedWindow("Mean filtered image (5x5)");
	cv::imshow("Mean filtered image (5x5)", result);

	// Blur the image (mean filter 9x9)
	cv::blur(image, result, cv::Size(9, 9));

	// Display mean filtered Image (9x9)
	cv::namedWindow("Mean filtered image (9x9)");
	cv::imshow("Mean filtered image (9x9)", result);

	// Blur the image (Gaussian filter 3x3)								// Gaussian Filter (sigma = 1)
	cv::GaussianBlur(image, result, cv::Size(3, 3), 1, 1);

	// Display Gaussian filtered Image (3x3)
	cv::namedWindow("Gaussian filtered image (3x3)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("Gaussian filtered image (3x3)(sigmaX = 1, sigmaY = 1)", result);
	
	// Blur the image (Gaussian filter 5x5)
	cv::GaussianBlur(image, result, cv::Size(5, 5), 1, 1);

	// Display Gaussian filtered Image (5x5)
	cv::namedWindow("Gaussian filtered image (5x5)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("Gaussian filtered image (5x5)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the image (Gaussian filter 9x9)
	cv::GaussianBlur(image, result, cv::Size(9, 9), 1, 1);

	// Display Gaussian filtered Image (9x9)
	cv::namedWindow("Gaussian filtered image (9x9)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("Gaussian filtered image (9x9)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the image (Gaussian filter 3x3)(sigmaX = 2, sigmaY = 2)					// Gaussian Filter (sigma = 2)
	cv::GaussianBlur(image, result, cv::Size(3, 3), 2, 2);

	// Display Gaussian filtered Image (3x3)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("Gaussian filtered image (3x3)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("Gaussian filtered image (3x3)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the image (Gaussian filter 5x5)(sigmaX = 2, sigmaY = 2)
	cv::GaussianBlur(image, result, cv::Size(5, 5), 2, 2);

	// Display Gaussian filtered Image (5x5)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("Gaussian filtered image (5x5)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("Gaussian filtered image (5x5)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the image (Gaussian filter 9x9)(sigmaX = 2, sigmaY = 2)
	cv::GaussianBlur(image, result, cv::Size(9, 9), 2, 2);

	// Display Gaussian filtered Image (9x9)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("Gaussian filtered image (9x9)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("Gaussian filtered image (9x9)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the image (median filter 3x3)								// Median Filter
	cv::medianBlur(image, result, 3);

	// Display median filter image (3x3)
	cv::namedWindow("Median filtered Image (3x3)");
	cv::imshow("Median filtered Image (3x3)", result);

	// Blur the image (median filter 5x5)
	cv::medianBlur(image, result, 5);

	// Display median filter image (5x5)
	cv::namedWindow("Median filtered Image (5x5)");
	cv::imshow("Median filtered Image (5x5)", result);

	// Blur the image (median filter 9x9)
	cv::medianBlur(image, result, 9);

	// Display median filter image (9x9)
	cv::namedWindow("Median filtered Image (9x9)");
	cv::imshow("Median filtered Image (9x9)", result);

	// Read as gray level image (Salt&Pepper)
	image = cv::imread("C:\\Users\\User\\Desktop\\sunset_salt6000.bmp", 0);
	if (!image.data)
		return 0;

	// Display the S&P original image
	cv::namedWindow("S&P image");
	cv::imshow("S&P image", image);

	// Blur the S&P image (mean filter 3x3)								// S&P Mean Filter
	cv::blur(image, result, cv::Size(3, 3));

	// Display S&P mean filtered image (3x3)
	cv::namedWindow("S&P mean filtered image (3x3)");
	cv::imshow("S&P mean filtered image (3x3)", result);

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

	// Blur the S&P image (Gaussian filter 3x3)							// S&P Gaussian Filter (sigma = 1)
	cv::GaussianBlur(image, result, cv::Size(3, 3), 1, 1);

	// Display S&P gaussian filtered Image (3x3)
	cv::namedWindow("S&P gaussian filtered image (3x3)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("S&P gaussian filtered image (3x3)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the S&P image (Gaussian filter 5x5)
	cv::GaussianBlur(image, result, cv::Size(5, 5), 1, 1);

	// Display S&P gaussian filtered Image (5x5)
	cv::namedWindow("S&P gaussian filtered image (5x5)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("S&P gaussian filtered image (5x5)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the S&P image (Gaussian filter 9x9)
	cv::GaussianBlur(image, result, cv::Size(9, 9), 1, 1);

	// Display S&P gaussian filtered Image (9x9)
	cv::namedWindow("S&P gaussian filtered image (9x9)(sigmaX = 1, sigmaY = 1)");
	cv::imshow("S&P gaussian filtered image (9x9)(sigmaX = 1, sigmaY = 1)", result);

	// Blur the S&P image (Gaussian filter 3x3)(sigmaX = 2, sigmaY = 2)				// S&P Gaussian Filter (sigma = 2)
	cv::GaussianBlur(image, result, cv::Size(3, 3), 2, 2);

	// Display S&P gaussian filtered Image (3x3)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("S&P gaussian filtered image (3x3)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("S&P gaussian filtered image (3x3)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the S&P image (Gaussian filter 5x5)(sigmaX = 2, sigmaY = 2)
	cv::GaussianBlur(image, result, cv::Size(5, 5), 2, 2);

	// Display S&P gaussian filtered Image (5x5)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("S&P gaussian filtered image (5x5)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("S&P gaussian filtered image (5x5)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the S&P image (Gaussian filter 9x9)(sigmaX = 2, sigmaY = 2)
	cv::GaussianBlur(image, result, cv::Size(9, 9), 2, 2);

	// Display S&P gaussian filtered Image (9x9)(sigmaX = 2, sigmaY = 2)
	cv::namedWindow("S&P gaussian filtered image (9x9)(sigmaX = 2, sigmaY = 2)");
	cv::imshow("S&P gaussian filtered image (9x9)(sigmaX = 2, sigmaY = 2)", result);

	// Blur the S&P image (median filter 3x3)							// S&P Median Filter
	cv::medianBlur(image, result, 3);

	// Display S&P median filter image (3x3)
	cv::namedWindow("S&P median filtered Image (3x3)");
	cv::imshow("S&P median filtered Image (3x3)", result);

	// Blur the S&P image (median filter 5x5)
	cv::medianBlur(image, result, 5);

	// Display S&P median filter image (5x5)
	cv::namedWindow("S&P median filtered Image (5x5)");
	cv::imshow("S&P median filtered Image (5x5)", result);

	// Blur the S&P image (median filter 9x9)
	cv::medianBlur(image, result, 9);

	// Display S&P median filter image (9x9)
	cv::namedWindow("S&P median filtered Image (9x9)");
	cv::imshow("S&P median filtered Image (9x9)", result);


	cv::waitKey();
	return 0;
}
