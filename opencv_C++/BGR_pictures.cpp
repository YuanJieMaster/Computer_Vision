#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat lena = cv::imread("maple_leaf.jpg");
    std::vector<cv::Mat> channels;
    cv::split(lena, channels);

    cv::Mat bgr;
    cv::merge(channels, bgr);

    cv::Mat brg = cv::Mat(channels[0].rows, channels[0].cols, CV_8UC3);
    cv::Mat brgChannels[] = { channels[0], channels[2], channels[1] };
    cv::merge(brgChannels, 3, brg);

    cv::Mat rgb;
    cv::Mat rgbChannels[] = { channels[2], channels[1], channels[0] };
    cv::merge(rgbChannels, 3, rgb);

    cv::imshow("bgr", bgr);
    cv::imshow("brg", brg);
    cv::imshow("rgb", rgb);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
