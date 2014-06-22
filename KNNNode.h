/*
 * KNNNode.h
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */

#ifndef KNNNODE_H_
#define KNNNODE_H_
#include<opencv2/ml/ml.hpp>
#include "Node.h"
#include <vector>

class KNN_Node : public Node
{
public:
	KNN_Node(unsigned k,long long _num,long label);
	float predict(const CvMat* samples,CvMat* results);
	virtual ~KNN_Node();
private:
	CvKNearest knn;
	unsigned int k;
};

#endif /* KNNNODE_H_ */
