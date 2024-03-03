#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat Image = imread("maple_leaf.jpg");

    Mat srcImage;

    cvtColor(Image, srcImage, COLOR_BGR2HSV);

    imshow("origin_picture",srcImage);

    Mat dstImage_blue, dstImage_red;

    inRange(srcImage, Scalar(100,43,46), Scalar(124,255,255), dstImage_blue);

    inRange(srcImage, Scalar(0,43,46), Scalar(10,255,255), dstImage_red);

    imshow("blue_picture",dstImage_blue);
    imshow("red_picture",dstImage_red);

    waitKey(0);

    return 0;
}
