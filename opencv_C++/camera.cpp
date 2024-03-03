#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    
    VideoCapture capture(0);

    Mat frame;
    
    while (true) {
        capture >> frame; // 从摄像头获取新的一帧
        imshow("Camera", frame);
        waitKey(30); //每30ms播放一帧
    }

    return 0;
}
