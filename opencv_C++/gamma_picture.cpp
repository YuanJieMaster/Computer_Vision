#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat image = imread("maple_leaf.jpg");
    long double gamma = 1/2.2;
    
    imshow("origin_picture",image);

    for(int i = 0;i < image.rows;i++){
        for(int j = 0;j < image.cols;j++){
            Vec3b pixel = image.at<Vec3b>(i,j);
            image.at<Vec3b>(i,j)[0] = pow(image.at<Vec3b>(i,j)[0]/255.0, gamma) * 255.0;
            image.at<Vec3b>(i,j)[1] = pow(image.at<Vec3b>(i,j)[1]/255.0, gamma) * 255.0;
            image.at<Vec3b>(i,j)[2] = pow(image.at<Vec3b>(i,j)[2]/255.0, gamma) * 255.0;
        }
    }

    imshow("gamma_picture",image);

    waitKey(0);

    return 0;
}
