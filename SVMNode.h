/*
 * SVMNode.h
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */

#ifndef SVMNODE_H_
#define SVMNODE_H_
#include "Node.h"

class SVM_Node : public Node{
public:
	SVM_Node(Node* _left,Node* _right,long long _num);
	virtual unsigned int predict(const Mat sample,float& dist);
	virtual Mat* get_data();
	virtual ~SVM_Node();
	SVM_Node();
	CvSVM svm;
	int feature_size;
	int data_type;

};

#endif /* SVMNODE_H_ */
