#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap;
    const string videoStreamAddress = "http://192.168.43.245:8080/video?dummy=param.mjpg";//ip摄像头地址
    //const string videoStreamAddress = "http://live.hkstv.hk.lxdns.com/live/hks/playlist.m3u8";//电视台的直播地址
    //const string videoStreamAddress = "http://img06.tooopen.com/images/20171116/tooopen_sy_228521528924.jpg";//网络图片地址
    cap.open(videoStreamAddress);
    //cap.open(0);//打开摄像头
    if (!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    namedWindow("当前视频", 0);
    for (;;)
    {
        cap >> frame; // get a new frame from camera
        imshow("当前视频", frame);
        if (waitKey(30) >= 0) break;
    }
    return 0;
}
