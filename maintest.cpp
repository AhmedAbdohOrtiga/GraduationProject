/*
 * maintest.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */
#include "Bolinomial.h"
#include "KNNNode.h"
#include <stdlib.h>

int main() {
	srand(time(NULL));

	Bolinomial* bb = new Bolinomial();
	float a[3][3] = { { 0.1, 0.2, 0.4 }, { 1., 3., 5 }, { 0., 2., 6. } };
	float b[3][3] = { { 5., 7., 6. }, { 9., 8., 2. }, { 10., 13., 11. } };
	float c[3][3] = { { 111, 33, 10 }, { 33, 31, 55 }, { 38, 44, 332 } };
	float d[3][3] = { { 20, 10, 3 }, { 33, 11, 30 }, { 4, 22, 33 } };

	Mat ma(3, 3, CV_32FC1, a);
	Mat mb(3, 3, CV_32FC1, b);
	Mat mc(3, 3, CV_32FC1, c);
	Mat md(3, 3, CV_32FC1, d);

	KNN_Node* na = new KNN_Node(2, rand() % ULLONG_MAX, 0, &ma);
	KNN_Node* nb = new KNN_Node(2, rand() % ULLONG_MAX, 1, &mb);
	KNN_Node* nc = new KNN_Node(2, rand() % ULLONG_MAX, 2, &mc);
//	KNN_Node* nd = new KNN_Node(2, rand() % ULLONG_MAX, 3, &md);

	bb->consolidate(na);
	bb->consolidate(nb);
	bb->consolidate(nc);
//	bb->consolidate(nd);
	bb->save();

	float t[3] = { 0.1, 0.2, 0.4 };
	float t1[3] = { 10, 10, 10 };
	float t2[3] = { 33, 31, 55 };
	float t3[3] = { 20, 20, 20 };
	cout << bb->perdict(Mat(1, 3, CV_32FC1, t)) << endl;
	cout << bb->perdict(Mat(1, 3, CV_32FC1, t1)) << endl;
	cout << bb->perdict(Mat(1, 3, CV_32FC1, t2)) << endl;
	cout << bb->perdict(Mat(1, 3, CV_32FC1, t3)) << endl;
	return 0;
}

