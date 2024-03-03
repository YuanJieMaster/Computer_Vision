#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(){
    Mat canvas = Mat::zeros(400, 300, CV_8UC3); //创建黑色画布
    Point center(200,150);
    int radius = 25;
    Scalar color(255,0,0);

    circle(canvas, center, radius, color, -1);

    imshow("circle",canvas);

    waitKey(0);

    return 0;
}
