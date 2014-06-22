/*
 * SVMNode.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */

#include "SVMNode.h"
#include <algorithm>

#define LEFT 0
#define RIGHT 1

SVM_Node::SVM_Node(Node* _left,Node* _right,long long _num) {
	num = _num;
	left = _left->get_num();
	right = _right->get_num();
	level = std::max(_left->get_level(),_right->get_level())+1;
	Mat* data_left = _left->get_data();
	Mat* data_right= _right->get_data();
	Mat data;
	vconcat(*data_left,*data_right,data);
	feature_size = data.cols;
	data_type = data.type();

	Mat labels_left(data_left->rows,1,data_left->type(),LEFT);
	Mat labels_right(data_right->rows,1,data_right->type(),RIGHT);
	Mat labels;
	vconcat(labels_left,labels_right,labels);

	svm.train(data,labels,Mat(),Mat(),CvSVMParams());

	// TODO serialize : save svm model and other members.

}

unsigned int SVM_Node::predict(const Mat sample,Mat* results)
{
	return (unsigned int)svm.predict(sample);
}

Mat* SVM_Node::get_data()
{
	unsigned sv_count = svm.get_support_vector_count();
	const float** vecs = (const float**)(malloc(sv_count*sizeof(const float*))) ;
	for(unsigned int i =0;i<sv_count;++i)
	{
		const float* vec = svm.get_support_vector(i);
		vecs[i]=vec;
	}

	Mat vectors(sv_count,feature_size,data_type,&vecs);

	return &vectors;
}

SVM_Node::~SVM_Node() {

}

