#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(){
    Mat srcImage = imread("maple_leaf.jpg");
    Mat dstImage_shallow = srcImage;
    Mat dstImage_deep;
    srcImage.copyTo(dstImage_deep);
    imshow("dstImage_shallow",dstImage_shallow);
    imshow("dstImage_deep",dstImage_deep);
    waitKey(0);
    return 0;
}

