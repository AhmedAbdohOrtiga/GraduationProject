/*
 * SVMNode.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */

#include "SVMNode.h"
#include <algorithm>

SVM_Node::SVM_Node(Node* _left,Node* _right) {
	left = _left;
	right = _right;
//	level = std::max,right->get_level())+1;
}

float SVM_Node::predict(const CvMat* samples,CvMat* results)
{
	return 0;
}

SVM_Node::~SVM_Node() {

}

