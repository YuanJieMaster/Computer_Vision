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
    for(int i = 0;i < dstImage_deep.rows;i++){
        for(int j = 0;j < dstImage_deep.cols;j++){
            Vec3b pixel = dstImage_deep.at<Vec3b>(i,j);
            int average = (pixel[0]+pixel[1]+pixel[2])/3.0;
            dstImage_deep.at<Vec3b>(i,j)[0] = dstImage_deep.at<Vec3b>(i,j)[1] = dstImage_deep.at<Vec3b>(i,j)[2] = average;
        }
    }
    imshow("origin_picture",srcImage);
    imshow("dstImage_deep",dstImage_deep);
    waitKey(0);
    return 0;
}
