// Standard Includes
#include <iostream>
#include <stdio.h>

// OpenCV Includes
#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"

// Project Includes
#include "Apple.h"

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){

// Open video stream
    VideoCapture myVideo;

    // Open from file
    if(argc > 1){
        cout << "Opening File..." << endl;
        myVideo.open(argv[1]);
    }

    // Open from webcam
    else{
        cout << "Opening Webcam..." << endl;
        myVideo.open(-1);
    }

    // Catch if failed to open
    if(!myVideo.isOpened()){
	cout << "Camera Didn't Open!" << endl;
        return -1;
    }

    vector< Apple > myApples;

    while(true){
        Mat frame;
        Mat HSV;
        Mat threshold;
        myVideo.read(frame);


// Find apples
        cvtColor(frame, HSV, COLOR_BGR2HSV);
	inRange(HSV, Scalar(100,100,100), Scalar(179,255,255),threshold);

// Track apples
        

// Draw apples
        Mat finalFrame;
	finalFrame = threshold;


// Display Video
        imshow("cam",finalFrame);
        int keypress = waitKey(30);
        if(keypress  == 'q'){
            break;
        }
    }

    return(0);
}


