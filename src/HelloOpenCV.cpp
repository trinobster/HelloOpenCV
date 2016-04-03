#include <opencv2/core/core.hpp>
//#include <opencv/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

Mat changecol(Mat img, int color);
Mat traspose(Mat img);
Mat flip(Mat img);
Mat mirror(Mat img);
Mat crop(Mat img, int point[], int k, int l);
Mat negative(Mat img);


int main( int argc, char** argv ){
    string imageName("/media/sf_fcg_lab/DIP/lena_color.jpg"); // by default
    if( argc > 1){
        imageName = argv[1];
    }

    //Mat img = Mat::zeros(500,500,CV_64F);

    Mat img;
    img = imread(imageName.c_str(), CV_LOAD_IMAGE_COLOR); // Read the file

    if( img.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "BEFORE", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "BEFORE", img );

/*    namedWindow( "AFTER CHANGECOLOR", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow("AFTER CHANGECOLOR", changecol(img, 0));

    namedWindow( "AFTER TRANSPOSE", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow("AFTER TRANSPOSE", traspose(img));

    namedWindow( "AFTER FLIPPING", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow("AFTER FLIPPING", flip(img));

    namedWindow( "AFTER MIRRORING", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow("AFTER MIRRORING", mirror(img));

    namedWindow( "AFTER CROPPING", WINDOW_AUTOSIZE ); // Create a window for display.
    int punto[2] = {300, 300};
    imshow("AFTER CROPPING", crop(img,punto, 70, 100));

  */namedWindow( "AFTER NEGATIVE", WINDOW_AUTOSIZE );
    imshow("AFTER NEGATIVE", negative(img));

    waitKey(0); // Wait for a keystroke in the window
    return 0;
}

Mat negative(Mat img){
	Mat neg = Mat::zeros(img.rows, img.cols,CV_8UC3); // metti CV_8C1 se vuoi usare l'immagine in bianco e nero

	for(int i = 0; i < img.rows; i++){
		for(int j = 0; j < img.cols; j++){
			neg.at<Vec3b>(i,j)[0] = 255 - img.at<Vec3b>(i,j)[0];
			neg.at<Vec3b>(i,j)[1] = 255 - img.at<Vec3b>(i,j)[1];
			neg.at<Vec3b>(i,j)[2] = 255 - img.at<Vec3b>(i,j)[2];
		}
	}

	return neg;
}

Mat crop(Mat img, int point[], int k, int l){
	Mat cropped = Mat::zeros(k,l,CV_8UC3);

	for(int i = 0; i < k; i++){
		for(int j = 0; j < l; j++){
			cropped.at<Vec3b>(i,j)[0] = img.at<Vec3b>(point[0] + i,point[1] + j)[0];
			cropped.at<Vec3b>(i,j)[1] = img.at<Vec3b>(point[0] + i,point[1] + j)[1];
			cropped.at<Vec3b>(i,j)[2] = img.at<Vec3b>(point[0] + i,point[1] + j)[2];
		}
	}

	return cropped;
}

Mat mirror(Mat img){
	Mat mirrored = Mat::zeros(img.rows,img.cols,CV_8UC3);

	for(int i = 0; i < img.rows; i++){
		for(int j = 0; j < img.cols; j++){
			//trasposta.at<uchar>(j,i) = img.at<uchar>(i,j);
			//CV_8UC1 1 = canale

			mirrored.at<Vec3b>(img.rows - i - 1,j)[0] = img.at<Vec3b>(i,j)[0];
			mirrored.at<Vec3b>(img.rows - i - 1,j)[1] = img.at<Vec3b>(i,j)[1];
			mirrored.at<Vec3b>(img.rows - i - 1,j)[2] = img.at<Vec3b>(i,j)[2];
		}
	}
	return mirrored;
}

Mat flip(Mat img){
	Mat flipped = Mat::zeros(img.rows,img.cols,CV_8UC3);

	for(int i = 0; i < img.rows; i++){
		for(int j = 0; j < img.cols; j++){
			//trasposta.at<uchar>(j,i) = img.at<uchar>(i,j);
			//CV_8UC1 1 = canale

			flipped.at<Vec3b>(i,img.cols - 1 - j)[0] = img.at<Vec3b>(i,j)[0];
			flipped.at<Vec3b>(i,img.cols - 1 - j)[1] = img.at<Vec3b>(i,j)[1];
			flipped.at<Vec3b>(i,img.cols - 1 - j)[2] = img.at<Vec3b>(i,j)[2];
		}
	}
	return flipped;
}

Mat traspose(Mat img){

	Mat trasposta = Mat::zeros(img.rows,img.cols,CV_8UC3);

	for(int i = 0; i < img.rows; i++){
			for(int j = 0; j < img.cols; j++){
				//trasposta.at<uchar>(j,i) = img.at<uchar>(i,j);
				//CV_8UC1 1 canale

				trasposta.at<Vec3b>(j,i)[0] = img.at<Vec3b>(i,j)[0];
				trasposta.at<Vec3b>(j,i)[1] = img.at<Vec3b>(i,j)[1];
				trasposta.at<Vec3b>(j,i)[2] = img.at<Vec3b>(i,j)[2];
			}
		}

	return trasposta;
}

Mat changecol(Mat img, int color){

	for(int i = 0; i < img.rows; i++){
		for(int j = 0; j < img.cols; j++){
			img.at<Vec3b>(i,j)[0] = color;
			img.at<Vec3b>(i,j)[1] = color;
			img.at<Vec3b>(i,j)[2] = color;
		}
	}

	return img;
}
