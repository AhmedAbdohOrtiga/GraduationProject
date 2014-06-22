/*
 * Node.h
 *
 *  Created on: Jun 21, 2014
 *      Author: hazem
 */

#ifndef NODE_H_
#define NODE_H_
#include <opencv2/core/core.hpp>

class Node {
public:
	long long get_left_child();
	long long get_right_child();
	unsigned int get_level();
	long long get_num();
	virtual CvMat* get_data();
	virtual float predict(const CvMat* samples,CvMat* results);
	virtual ~Node();
protected :
	long long num;
	long long left;
	long long right;
	unsigned int level;
};

#endif /* NODE_H_ */
