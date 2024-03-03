#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat image = imread("maple_leaf.jpg");
    
    int threshold = 127;
    
    imshow("origin_picture",image);

    for(int i = 0;i < image.rows;i++){
        for(int j = 0;j < image.cols;j++){
            Vec3b pixel = image.at<Vec3b>(i,j);
            int average = (pixel[0]+pixel[1]+pixel[2])/3.0;
            if(average > threshold){
            	image.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,j)[2] = 255;
            }
            else{
            	image.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,j)[2] = 0;
            }
        }
    }

    imshow("average_picture",image);

    waitKey(0);

    return 0;
}
