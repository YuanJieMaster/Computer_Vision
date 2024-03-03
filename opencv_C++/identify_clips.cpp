#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat image = imread("12.png");
    
    int threshold = 64;

    resize(image, image, Size(500, 450));
    
    imshow("origin_picture",image);

    for(int i = 0;i < image.rows;i++){
        for(int j = 0;j < image.cols;j++){
            Vec3b pixel = image.at<Vec3b>(i,j);
            int average = (pixel[0]+pixel[1]+pixel[2])/3.0;
            if(average > threshold){
            	image.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,j)[2] = 0;
            }
            else{
            	image.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,j)[2] = 255;
            }
        }
    }
    
    cvtColor(image, image, COLOR_BGR2GRAY);

    imshow("binaryzation_picture",image);

    vector<vector<Point>> contours;

    Mat hierarchy;

    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    cvtColor(image, image, COLOR_GRAY2BGR);

    drawContours(image, contours, -1, Scalar(0, 255, 0));

    cout << "回形针数量: " << contours.size() << endl;
    
    imshow("stroke_picture", image);

    waitKey(0);

    return 0;
}
