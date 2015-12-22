//
// Created by rharriso on 22/12/15.
//
#include <iostream>
#include <algorithm>
#include <memory>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << " Usage: masks image_to_sharpen" << endl;
        return -1;
    }

    auto img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat sharpImg;

    if (!img.data) {
        cout << "Couldn't open the img: " << argv[1] << endl;
        return -1;
    }

    // apply sharp kernel
    auto kern = (Mat)(Mat_<int>(3,3) <<  0, -1,  0,
                                         -1,  5, -1,
                                         0, -1,  0);
    filter2D(img, sharpImg, img.depth(), kern);

    namedWindow("Image", WINDOW_NORMAL | WINDOW_OPENGL);
    imshow("Image", img);
    namedWindow("Sharpened Image", WINDOW_NORMAL | WINDOW_OPENGL);
    imshow("Sharpened Image", sharpImg);
    waitKey(0);

    return 0;
}
