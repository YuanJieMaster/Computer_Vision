#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    Mat srcImage = imread("./maple_leaf.jpg");
    imshow("origin_picture",srcImage);
    waitKey(0);
    return 0;
}