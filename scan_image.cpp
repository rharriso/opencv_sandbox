//
// Created by rharriso on 21/12/15.
//
#include <iostream>
#include <algorithm>
#include <memory>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

shared_ptr<Mat> scan_and_reduce_color_space(const Mat &I, const vector<uchar> &table);

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << " Usage: scan_image imageToScan colorCrush" << endl;
        return -1;
    }

    auto image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if (!image.data) {
        cout << "Couldn't open the image: " << argv[1] << endl;
        return -1;
    }

    int divideWith = 0;
    stringstream s;
    s << argv[2];
    s >> divideWith;

    if(!s || !divideWith){
        cout << "Can't use divide width: " << argv[2] << endl;
        return -1;
    }

    auto table = vector<uchar>(vector<uchar>(256));
    uchar index = 0;
    generate(table.begin(), table.end(), [&divideWith, &index](){
        return divideWith * ((++index) / divideWith);
    });

    auto reducedImage = scan_and_reduce_color_space(image, table);

    namedWindow("Display Window", WINDOW_NORMAL | WINDOW_OPENGL);
    imshow("Display Window", *reducedImage.get());
    waitKey(0);

    return 0;
}

shared_ptr<Mat> scan_and_reduce_color_space(const Mat &I, const vector<uchar> &table) {
    // accept only char type matrices
    CV_Assert(I.depth() != sizeof(uchar));
    auto result = make_shared<Mat>(I.clone());

    const int channels = I.channels();

    switch (channels) {
        case 1: {
            transform(I.begin<uchar>(), I.end<uchar>(), result->begin<uchar>(), [&table](uchar p){
                return table.at(p);
            });
        }
        case 3: {
            transform(I.begin<Vec3b>(), I.end<Vec3b>(), result->begin<Vec3b>(), [&table](Vec3b p) {
                return Vec3b(table.at(p[0]), table.at(p[1]),table.at(p[2]));
            });
        }
    }

    return result;
}

