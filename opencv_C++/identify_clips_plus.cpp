#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("12.png");
    imshow("原图片", src);
    // 二值化
    Mat dst, gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    threshold(gray, binary, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
    // 形态学去除干扰
    Mat k = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
    morphologyEx(binary, binary, MORPH_OPEN, k);
    imshow("binary", binary);
    // 轮廓发现与绘制
    vector<vector<Point>> contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point());
    for (size_t t = 0; t < contours.size(); t++) {
        vector<Point> hull;
        convexHull(contours[t], hull);//凸包检测
        bool isHull = isContourConvex(contours[t]);//判断轮廓是否为凸包
        printf("test convex of the contours %s\n", isHull ? "Y" : "N");
        int len = hull.size();
        //绘制凸包
        for (int i = 0; i < hull.size(); i++) {
            circle(src, hull[i], 4, Scalar(255, 0, 0), 2, 8, 0);//点
            line(src, hull[i%len], hull[(i + 1) % len], Scalar(0, 0, 255), 2, 8, 0);//线
        }
    }
    imshow("凸包检测", src);
    waitKey(0);
}
