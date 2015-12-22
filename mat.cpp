//
// Created by rharriso on 21/12/15.
//
#include <iostream>
#include <algorithm>
#include <chrono>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main(){
    // using built in array pixel types
    auto M = Mat(2,2, CV_8UC3, Scalar(0, 0, 255));
    cout << "M: " << M << endl << endl;

    // using c++ array to create 3d matrix of 3 value pixels
    int sz[3] = {2,2,2};
    auto L = Mat(3, sz, CV_8UC(3), Scalar(0, 0, 255));

    // vector of 3d points
    srand(time(0));
    auto points = vector<Point3d>(20);
    generate(points.begin(), points.end(), [](){
        return Point3d(rand() % 256, rand() % 256, rand() % 256);
    });
    cout << "Vector of 3d points" << points << endl << endl;

    return 0;
}
