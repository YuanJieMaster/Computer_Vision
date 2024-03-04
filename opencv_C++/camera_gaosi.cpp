#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    
    VideoCapture capture(0);

    Mat frame, dst;
    
    while (true) {
        capture >> frame; // 从摄像头获取新的一帧
        double sigmaX;//高斯核函数在X方向的的标准偏差
        double sigmaY;//高斯核函数在Y方向的的标准偏差，若
        GaussianBlur(frame, dst, cv::Size(5, 5), sigmaX, sigmaY);
        imshow("Camera_origin", frame);
        imshow("Camera", dst);
        waitKey(30); //每30ms播放一帧
    }

    return 0;
}
