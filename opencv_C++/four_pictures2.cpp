#include <opencv2/opencv.hpp>
using namespace cv;

int main() {

    int screen_width = 800;
    int screen_length = 1280;

    int window_width = 300;
    int window_length = 400;


    Mat srcImage = imread("./maple_leaf.jpg");
    Mat dstImage;
    resize(srcImage, dstImage, Size(40, 30));
    imshow("Top_Left",dstImage);
    moveWindow("Top_Left",0,0);

    waitKey(0);
    return 0;
}
