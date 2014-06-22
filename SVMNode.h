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
	SVM_Node(Node* _left,Node* _right);
	float predict(const CvMat* samples,CvMat* results);
	virtual ~SVM_Node();
};

#endif /* SVMNODE_H_ */
