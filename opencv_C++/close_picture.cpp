#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv; 

int main()
{
    Mat srcImage = imread("9.png");
    imshow("origin_picture",srcImage); 

    Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
    Mat tempImage, dstImage;
    dilate(srcImage, tempImage, element);
    erode(tempImage, dstImage, element);

    imshow("闭运算",dstImage);

    waitKey(0); 
}
