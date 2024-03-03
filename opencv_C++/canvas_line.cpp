#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(){
    Mat canvas = Mat::zeros(400, 300, CV_8UC3); //创建黑色画布

    Scalar color = Scalar(0, 255, 0);

    Point p1 = Point(20,30);
    Point p2 = Point(300,300);

    line(canvas, p1, p2, color);

    imshow("line",canvas);

    waitKey(0);

    return 0;
}
