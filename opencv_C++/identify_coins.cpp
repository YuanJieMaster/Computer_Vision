#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat image = imread("11.png");
    
    int threshold = 84;

    resize(image, image, Size(500, 450));
    
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
    
    cvtColor(image, image, COLOR_BGR2GRAY);

    imshow("binaryzation_picture",image);
    
    Mat labeledImage;
    Mat stats, centroids;
    int numLabels = connectedComponentsWithStats(image, labeledImage, stats, centroids);
    
    printf("%d\n", numLabels-1);
    
    labeledImage.convertTo(labeledImage, CV_8U);

    normalize(labeledImage, labeledImage, 0, 255, NORM_MINMAX);


    imshow("Labeled Picture", labeledImage);
    
    cvtColor(image, image, COLOR_GRAY2BGR);
    
    for (int i = 1; i < numLabels; ++i) {
        Point center((int)(centroids.at<double>(i, 0)), (int)(centroids.at<double>(i, 1)));
        circle(image, center, 3, Scalar(255, 0, 0), -1); //绘制重心
        Rect rect(stats.at<int>(i,0), stats.at<int>(i,1), stats.at<int>(i,2), stats.at<int>(i,3)); 
        Scalar color(0, 255, 0);
        rectangle(image, rect, color); 
    }
    
    imshow("centers_picture", image);

    waitKey(0);

    return 0;
}
