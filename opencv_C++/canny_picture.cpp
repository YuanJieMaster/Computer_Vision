#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()
{
    Mat srcImage = imread("./maple_leaf.jpg");
    imshow("origin_picture", srcImage);
    Mat dstImage, edge, grayImage;

    //创建与src同类型和大小的矩阵
    dstImage.create( srcImage.size(), srcImage.type());

    //转灰
    cvtColor( srcImage, grayImage, COLOR_BGR2GRAY ); //按OpenCV3的来

    blur( grayImage, edge, Size(3,3) );

    Canny(edge, edge, 3, 9, 3); //运行Canny

    imshow("Cannied_picture", edge);

    waitKey(0);

    return 0;
}
