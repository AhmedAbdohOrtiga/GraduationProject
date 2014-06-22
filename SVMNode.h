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
	unsigned int predict(const Mat sample,Mat* results);
	Mat* get_data();
	virtual ~SVM_Node();
private:
	CvSVM svm;
	unsigned feature_size;
	int data_type;

};

#endif /* SVMNODE_H_ */
