#include <opencv2/opencv.hpp>
using namespace cv; 

int main()
{
    Mat srcImage = imread("./maple_leaf.jpg");
    Mat dstImage;
    resize(srcImage,dstImage,Size(400,300));
    imshow("origin_picture",dstImage);
    waitKey(0);
    return 0;
}