#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat srcImage = imread("maple_leaf.jpg");

    Mat dstImage;

    cvtColor(srcImage, dstImage, COLOR_BGR2HSV);
    
    imshow("origin_picture",srcImage);

    imshow("HSV_picture",dstImage);

    waitKey(0);

    return 0;
}
