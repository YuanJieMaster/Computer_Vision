#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    
    VideoCapture capture(0);

    Mat frame;
    double fps, t;
    char string[10]; //存放帧率
    double before = (double)getTickCount();

    while (1) {
        capture >> frame; // 从摄像头获取新的一帧
        t = ((double)getTickCount() - before)/getTickFrequency();
        before = (double)getTickCount();
        fps = 1.0 / t;
        printf("fps: %.2f\n", fps);
    }

    return 0;
}
