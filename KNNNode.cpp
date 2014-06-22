#include "KNNNode.h"
#include <fstream>
#include <sstream>

KNN_Node::KNN_Node(unsigned _k,long long _num,long label) {
	left = 0;
	num = _num;
	right = 0;
	level = 0;
	k = _k;
	std::ifstream f;
	std::stringstream ss;
	std::string strnum;
	ss << num;
	ss >> strnum;
	std::vector<CvMat> data;

}

float KNN_Node::predict(const CvMat* samples,CvMat* results)
{
	return knn.find_nearest(samples,k,results);
}

KNN_Node::~KNN_Node() {
}
