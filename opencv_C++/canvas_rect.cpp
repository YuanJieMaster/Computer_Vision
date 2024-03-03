#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
    Mat canvas = Mat::zeros(400, 300, CV_8UC3); // 创建一个黑色画布

    Rect rect(50, 50, 200, 150); 
    Scalar color(0, 255, 0);

    rectangle(canvas, rect, color); 

    imshow("Rect", canvas);

    waitKey(0);

    return 0;
}

