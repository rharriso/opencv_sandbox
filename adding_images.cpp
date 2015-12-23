#include <iostream>
#include <algorithm>
#include <memory>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << " Usage: adding_images image_1 image_2" << endl;
        return -1;
    }

    auto img1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    auto img2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);

    if (!img1.data) {
        cout << "Couldn't open the img1: " << argv[1] << endl;
        return -1;
    }

    if (!img2.data) {
        cout << "Couldn't open the img2: " << argv[2] << endl;
        return -1;
    }

    if (img1.size != img2.size){
        cout << "Images are different sizes: " <<
        "(" << img1.rows << " " << img1.cols << ")" << " " <<
        "(" << img2.rows << " " << img2.cols << ")" << endl;
        return -1;
    }

    auto alpha = 0.8;
    auto beta  = 1.0 - alpha;
    Mat blend;

    addWeighted(img1, alpha, img2, beta, 0.0, blend);

    namedWindow("Image1", WINDOW_NORMAL | WINDOW_OPENGL);
    imshow("Image1", img1);

    namedWindow("Image2", WINDOW_NORMAL | WINDOW_OPENGL);
    imshow("Image2", img2);

    namedWindow("Blend", WINDOW_NORMAL | WINDOW_OPENGL);
    imshow("Blend", blend);

    waitKey(0);
    return 0;
}
