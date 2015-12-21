#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    if(argc != 2){
        cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!image.data){
        cout << "Couldn't open the image: " << argv[1] << endl;
    }

    namedWindow("Display Window", WINDOW_AUTOSIZE);
    imshow("Display Window", image);

    waitKey(0);
    return 0;
}