#include <opencv2/opencv.hpp>
using namespace cv;

int main() {

    int screen_width = 800;
    int screen_length = 1280;

    int window_width = 300;
    int window_length = 400;


    Mat srcImage = imread("./maple_leaf.jpg");
    Mat dstImage;
    resize(srcImage, dstImage, Size(400, 300));
    namedWindow("Top_Left",WINDOW_NORMAL);
    imshow("Top_Left",dstImage);
    moveWindow("Top_Left",0,0);

    namedWindow("Top_Right",WINDOW_NORMAL);
    imshow("Top_Right",dstImage);
    moveWindow("Top_Right",screen_length-window_length-1,0);

    namedWindow("Bottom_Left",WINDOW_NORMAL);
    imshow("Bottom_Left",dstImage);
    moveWindow("Bottom_Left",0,screen_width-window_width-1);

    namedWindow("Bottom_Right",WINDOW_NORMAL);
    imshow("Bottom_Right",dstImage);
    moveWindow("Bottom_Right",screen_length-window_length-1,screen_width-window_width-1);

    waitKey(0);
    return 0;
}
