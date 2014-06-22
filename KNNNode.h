/*
 * KNNNode.h
 *
 *  Created on: Jun 22, 2014
 *      Author: hazem
 */

#ifndef KNNNODE_H_
#define KNNNODE_H_
#include "Node.h"
#include <vector>

class KNN_Node : public Node
{
public:
	KNN_Node(unsigned k,long long _num,long label ,Mat* _data);
	unsigned int predict(cv::Mat sample,cv::Mat* results);
	Mat* get_data();
	virtual ~KNN_Node();
private:
	Mat* data;
	long label;
	unsigned int k;
};

#endif /* KNNNODE_H_ */
