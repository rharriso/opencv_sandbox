#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    if(argc != 2){
        cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
        return -1;
    }

    auto imageName = string(argv[1]);
    auto image = imread(imageName);

    if(!image.data){
        cout << "No image data for: " << imageName;
    }

    // create and write gray image
    Mat gray_image;
    cvtColor(image, gray_image, CV_BGR2GRAY);
    imwrite("../out.jpg", gray_image);

    // show images
    namedWindow(imageName, CV_WINDOW_NORMAL);
    imshow(imageName, image);
    namedWindow("Gray Image", CV_WINDOW_NORMAL);
    imshow("Gray Image", gray_image);

    waitKey(0);
    return 0;
}
