#include "KNNNode.h"
#include <fstream>
#include <sstream>
#include <opencv2/ml/ml.hpp>


KNN_Node::KNN_Node(unsigned _k,long long _num,long _label,Mat* _data) {
	left = 0;
	num = _num;
	right = 0;
	level = 0;
	label = _label;
	data = _data;
	k = _k;

	// TODO serialize or in other words save this member variables
}

Mat* KNN_Node::get_data()
{
	return data;
}

unsigned int KNN_Node::predict(const cv::Mat sample,cv::Mat* results)
{
	CvKNearest knn;
	Mat labels (data->rows,1,label);
	knn.train(*data,labels,Mat(),false,k);
	knn.find_nearest(sample,k,results);
	return label;
}

KNN_Node::~KNN_Node() {
}
