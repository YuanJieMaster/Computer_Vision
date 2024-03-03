#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(){
    Mat canvas = Mat::zeros(400, 300, CV_8UC3); //创建黑色画布

    Vec3b color(0, 0, 255);

    canvas.at<Vec3b>(200, 150) = color;

    imshow("Point",canvas);

    waitKey(0);

    return 0;
}
