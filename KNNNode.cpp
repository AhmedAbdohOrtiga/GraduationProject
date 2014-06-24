#include "KNNNode.h"

KNN_Node::KNN_Node() {
	data = new Mat();
	k = 0;
	left = -1;
	right = -1;
	label = 0;
	level = 0;
}

KNN_Node::KNN_Node(unsigned _k, long long _num, long _label, Mat* _data) {
	left = 0;
	num = _num;
	right = 0;
	level = 0;
	label = _label;
	data = _data;
	k = _k;

	// TODO serialize or in other words save this member variables(data and the rest)
	FileStorage* f = serialize();

	*f << "label" << (double) label;
	*f << "k" << (int) k;
	*f << "data" << *data;

	f->release();
}

Mat* KNN_Node::get_data() {
	return data;
}

unsigned int KNN_Node::predict(const Mat sample, float& dis) {
	CvKNearest knn;
	Mat labels(data->rows, 1, label);
	knn.train(*data, labels, Mat(), false, k);
	Mat dists;
	Mat r;
	Mat rr;
	// TODO fix passed params
	knn.find_nearest(sample, k, r, rr, dists);
	dis = *(std::min_element(dists.begin<float>(), dists.end<float>()));
	// set dis to min dis
	return label;
}

KNN_Node::~KNN_Node() {
}
