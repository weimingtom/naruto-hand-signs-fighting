/*
 * MyFourier.cxx
 *
 *  Created on: Nov 9, 2010
 *      Author: michele
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "MyFourier.h"

using namespace std;

MyFourier myFourier;

void MyFourier::speedyConvolution(const CvMat* A, const CvMat* B, CvMat* C){

	int dft_M = cvGetOptimalDFTSize(A->rows + B->rows - 1);
	int dft_N = cvGetOptimalDFTSize(A->cols + B->cols - 1);

	CvMat* dft_A = cvCreateMat(dft_M, dft_N, A->type);
	CvMat* dft_B = cvCreateMat(dft_M, dft_N, B->type);
	CvMat tmp;

	try{
		// copy A to dft_A and pad dft_A with zeros
		cvGetSubRect(dft_A, &tmp, cvRect(0, 0, A->cols, A->rows));
		cvCopy(A, &tmp);
		cvGetSubRect( dft_A, &tmp, cvRect(A->cols, 0, dft_A->cols, A->rows));
		cvSetZero(&tmp);

		// no need to pad bottom part of dft_A with zeros because of
		// use nonzero_rows parameter in cvDFT() call below
		cvDFT(dft_A, dft_A, CV_DXT_FORWARD, A->rows);
	}catch(cv::Exception e){
		cout<<"Exception computing DFT of A\n" << e.err <<"\n";
//		cout<<"Error type code: " << e.code << "\n" ;
//		cout<<"Error msg: " << e.msg << "\n" ;
//		cout<<"Located in: " << e.file << "line: " << e.line <<"\n";
	}

	try{
		// repeat the same with the second array
		cvGetSubRect(dft_B, &tmp, cvRect(0,0, B->cols, B->rows));
		cvCopy(B, &tmp);
		cvGetSubRect(dft_B, &tmp, cvRect(B->cols, 0, dft_B->cols - B->cols, B->rows));
		cvSetZero(&tmp);

		// no need to pad the bottom part of dft_B with zeros because of
		// use nonzero_rows parameter in cvDFT() call below
		cvDFT(dft_B, dft_B, CV_DXT_FORWARD, B->rows);
	}catch(cv::Exception e){
		cout<<"Exception computing DFT of B\n" << e.err <<"\n";
	}

	cvMulSpectrums(dft_A, dft_B, dft_A, 0);

	// calculate only the top part

	cvDFT(dft_A, dft_A, CV_DXT_INV_SCALE, C->rows);
	cvGetSubRect(dft_A, &tmp, cvRect(0,0,C->cols, C->rows));

	cvCopy(&tmp, C);

	cvReleaseMat(&dft_A);
	cvReleaseMat(&dft_B);


}

int MyFourier::buildFilter(int rows, int columns, int type,
		int filterType, int order, double fc, CvMat* outputFilter ){

	//the image should be square

//	CvMat *mask = cvCreateMat(rows, columns , type );

	int Xmin = -rows/2;
	int Ymin = -columns/2;

	try{
		// transfer function filter matrix
		for(int i=0; i<rows; i++){
			for(int j=0; j<columns; j++)
			{
				double dxy = sqrt( pow(Xmin+i, 2) + pow(Ymin+j,2) );
				double H;

				if(filterType == FILTER_TYPE_LOWPASS){
					H = (1/(1 + pow(dxy/fc, 2*order))); //low pass function
				}
				if(filterType == FILTER_TYPE_HIGHPASS){
					if(dxy==0){
						H=0;
					}else
						H = (1/(1 + pow(fc/dxy, 2*order)));   //high pass function
				}
//				cout <<"i: " << i <<" j: " << j << " H: " << H << "\n";

				cvSetReal2D(outputFilter, j, i, H);
			}
		}

//		outputFilter = mask;
//		cvCopy(mask, outputFilter);
		return 1;
	}catch(cv::Exception e){
		outputFilter = NULL;
		cout << e.err <<"\n";
		return e.code;
	}
}
