/*
 * KNNNode.h
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */

#ifndef KNNNODE_H_
#define KNNNODE_H_
#include "Node.h"

class KNN_Node : public Node
{
public:
	KNN_Node(unsigned k,long long _num,long label ,Mat* _data);
	unsigned int predict(const Mat sample,float& dis);
	Mat* get_data();
	virtual ~KNN_Node();
	KNN_Node();
	Mat* data;
	double label;
	int k;
};

#endif /* KNNNODE_H_ */
