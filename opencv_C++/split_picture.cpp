#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat scrImage = imread("./maple_leaf.jpg");
    vector<Mat> mv;
    split(scrImage, mv);
    imshow("B通道",mv[0]);
    imshow("G通道",mv[1]);
    imshow("R通道",mv[2]);
    waitKey(0);
    return 0;
}
