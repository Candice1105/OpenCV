#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main()
{
    // Read as gray level image
    cv::Mat image = cv::imread("C:\\Users\\User\\Desktop\\snowman.jpg", 0);
    if (!image.data)
        return 0;
    // Display original image
    cv::namedWindow("Original image");
    cv::imshow("Original image", image);

    cv::Mat sobelX;
    // Get differential image (3x3)(sobelX)
    cv::Sobel(image, sobelX, CV_8U, 1, 0,  3, 1, 128);
    // Display sobel filter image (3x3)(sobelX)
    cv::namedWindow("sobelX image (3x3)");
    cv::imshow("sobelX image (3x3)", sobelX);

    cv::Mat sobelY;
    // Get differential image (3x3)(sobelY)
    cv::Sobel(image, sobelY, CV_8U, 0, 1, 3, 1, 128);
    // Display sobel filter image (3x3)(sobelY)
    cv::namedWindow("sobelY image (3x3)");
    cv::imshow("sobelY image (3x3)", sobelY);

    cv::Mat sobelXY;
    // Get differential image (3x3)(sobelXY)
    cv::Sobel(image, sobelXY, CV_8U, 1, 1, 3, 1, 128);
    // Display sobel filter image (3x3)(sobelXY)
    cv::namedWindow("sobelXY image (3x3)");
    cv::imshow("sobelXY image (3x3)", sobelXY);

    // Get differential image (5x5)(sobelX)
    cv::Sobel(image, sobelX, CV_8U, 1, 0, 5, 1, 128);
    // Display sobel filter image (5x5)(sobelX)
    cv::namedWindow("sobelX image (5x5)");
    cv::imshow("sobelX image (5x5)", sobelX);

    // Get differential image (5x5)(sobelY)
    cv::Sobel(image, sobelY, CV_8U, 0, 1, 5, 1, 128);
    // Display sobel filter image (5x5)(sobelY)
    cv::namedWindow("sobelY image (5x5)");
    cv::imshow("sobelY image (5x5)", sobelY);

    // Get differential image (5x5)(sobelXY)
    cv::Sobel(image, sobelXY, CV_8U, 1, 1, 5, 1, 128);
    // Display sobel filter image (5x5)(sobelXY)
    cv::namedWindow("sobelXY image (5x5)");
    cv::imshow("sobelXY image (5x5)", sobelXY);

    // Get differential image (7x7)(sobelX)
    cv::Sobel(image, sobelX, CV_8U, 1, 0, 7, 1, 128);
    // Display sobel filter image (7x7)(sobelX)
    cv::namedWindow("sobelX image (7x7)");
    cv::imshow("sobelX image (7x7)", sobelX);

    // Get differential image (7x7)(sobelY)
    cv::Sobel(image, sobelY, CV_8U, 0, 1, 7, 1, 128);
    // Display sobel filter image (7x7)(sobelY)
    cv::namedWindow("sobelY image (7x7)");
    cv::imshow("sobelY image (7x7)", sobelY);

    // Get differential image (7x7)(sobelXY)
    cv::Sobel(image, sobelXY, CV_8U, 1, 1, 7, 1, 128);
    // Display sobel filter image (7x7)(sobelXY)
    cv::namedWindow("sobelXY image (7x7)");
    cv::imshow("sobelXY image (7x7)", sobelXY);

    cv::Mat result;
    // Get differential image (3x3)(laplacian)
    cv::Laplacian(image, result, CV_8U, 3, 1, 128);
    // Display laplacian filter image (3x3)(laplacian)
    cv::namedWindow("laplacian image (3x3)");
    cv::imshow("laplacian image (3x3)", result);

    // Get differential image (5x5)(laplacian)
    cv::Laplacian(image, result, CV_8U, 5, 1, 128);
    // Display laplacian filter image (5x5)(laplacian)
    cv::namedWindow("laplacian image (5x5)");
    cv::imshow("laplacian image (5x5)", result);

    // Get differential image (7x7)(laplacian)
    cv::Laplacian(image, result, CV_8U, 7, 1, 128);
    // Display laplacian filter image (7x7)(laplacian)
    cv::namedWindow("laplacian image (7x7)");
    cv::imshow("laplacian image (7x7)", result);

    cv::waitKey();
    return 0;
}
