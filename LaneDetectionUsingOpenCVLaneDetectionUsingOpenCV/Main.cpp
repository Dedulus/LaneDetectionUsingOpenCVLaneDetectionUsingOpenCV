//C++ program to detect lanes from the input image

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	// Read the input image
	Mat img = imread("lane2.jpg");

	// Convert the image to grayscale
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	// Apply Canny edge detection
	Mat edges;
	Canny(gray, edges, 100, 200);

	// Apply Hough line transform
	vector<Vec4i> lines;
	HoughLinesP(edges, lines, 1, CV_PI / 180, 50, 50, 10);

	// Draw the detected lanes
	for (size_t i = 0; i < lines.size(); i++)
	{
		line(img, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 3, 8);
	}

	// Save grayscale image
	imwrite("lane2_converted.jpg", img);


	// Display the output image
	imshow("Lane Detection", img);
	waitKey(0);

	return 0;
}