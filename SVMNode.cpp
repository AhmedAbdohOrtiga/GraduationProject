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

SVM_Node::SVM_Node()
{

}

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

	Mat labels_left(data_left->rows,1,data_left->type(),(float)LEFT);
	Mat labels_right(data_right->rows,1,data_right->type(),(float)RIGHT);
	Mat labels;
	vconcat(labels_left,labels_right,labels);

	svm.train(data,labels,Mat(),Mat(),CvSVMParams());

	// TODO serialize : save svm model and other members.

	FileStorage* f = serialize();
	*f << "left" << left;
	*f << "right" << right;
	*f << "feature_size" << feature_size;
	*f << "data_type" << data_type;
	f->release();

	std::ostringstream ff;
	ff << BASEPATH;
	ff <<'/';
	ff << num;
	ff << "/model.xml";

	svm.save(ff.str().c_str());


}

unsigned int SVM_Node::predict(const Mat sample,float& dist)
{
	return (unsigned int)svm.predict(sample);
}

Mat* SVM_Node::get_data()
{
	unsigned sv_count = svm.get_support_vector_count();
	float* vecs = (float*)(malloc(sv_count*feature_size*sizeof(float))) ;
	for(unsigned int i =0;i<sv_count;++i)
	{
		const float* vec = svm.get_support_vector(i);
		for(int j = 0;j<feature_size;++j)
		{
			vecs[i*sv_count+j]=vec[i];
		}
	}

	Mat* vectors = new Mat(sv_count,feature_size,data_type,vecs);

	return vectors;
}

SVM_Node::~SVM_Node() {

}

