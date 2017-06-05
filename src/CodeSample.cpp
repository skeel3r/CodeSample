// Standard Includes
#include <iostream>
#include <stdio.h>

// OpenCV Includes
#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"
//#include "opencv2/cudafilters.hpp" // Was using gpu based filters
//#include "opencv2/features2d.hpp"

// Project Includes
#include "Banana.h"
#include "Calibrator.h"

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

    // Defining Variables
    int minH = 20;
    int maxH = 30;
    int minS = 100;
    int maxS = 255;
    int minV = 100; 
    int maxV = 255; // Vars for hsv thresholding filter   

    cout << "Beginning video manipulation" << endl;
    while(true){
        vector< Banana > myBananas;
        Mat frame, frame2;
        Mat hsv;
        Mat threshold1, threshold2;
        myVideo.read(frame);
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        // Filter for bananas
        inRange(hsv, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), threshold2);

        // Classify Bananas
        CascadeClassifier banana_cascade("banana_classifier.xml");
        std::vector<Rect> bananas;
        // Input Mat, vector, scale factor, neighboring rectangles, min/max sizes
        banana_cascade.detectMultiScale(hsv, bananas, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE, Size(60, 60) );

        // Draw ellipse around the detected bananas
        for( int i = 0; i < bananas.size(); i++ ){
            Banana newBanana;
            Point center( bananas[i].x + bananas[i].width*0.5, bananas[i].y + bananas[i].height*0.5 );
            ellipse( frame, center, Size( bananas[i].width*0.5, bananas[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
            newBanana.setX(bananas[i].x);
            newBanana.setY(bananas[i].y);
            myBananas.push_back(newBanana); // Add detected banana to vector
        }
	cout << "NUM OF BANANAS = " << myBananas.size() << endl;

        // Display Video
        imshow("cam",frame);
        int keypress = waitKey(30);
        if(keypress  == 'q'){
            break; // Exit
        }
        if(keypress  == 'c'){
            calibrate = true; // Calibrate
        }
    }

    return(0);
}


