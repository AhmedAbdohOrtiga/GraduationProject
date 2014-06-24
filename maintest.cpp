/*
 * maintest.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */
#include "Bolinomial.h"

int main()
{

//	Bolinomial* bb = new Bolinomial();
	float a[3][3] = {{0.1,0.2,0.4},{1,3,5},{0,2,6}};
	float b[3][3] = {{5,7,6},{9,8,2},{10,13,11}};

	Mat ma(3,3,CV_32FC1,a);
	Mat mb(3,3,CV_32FC1,b);

	KNN_Node* na =KNN_Node(2,0,0,*ma);
	KNN_Node* nb =KNN_Node(2,1,1,*ma);

//	bb->consolidate(na);
//	bb->consolidate(nb);

	float t[3] = {0.1,0.2,0.4};
	float t1[3] = {2,2,1};

	cout << bb->perdict(Mat(1,3,CV_32FC1,t)) << endl;
	cout << bb->perdict(Mat(1,3,CV_32FC1,t1)) << endl;


	return 0;
}



