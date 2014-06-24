/*
 * Node.h
 *
 *  Created on: Jun 21, 2014
 *      Author: hazem
 */

#ifndef NODE_H_
#define NODE_H_
#include <opencv2/core/core.hpp>
#include <opencv2/ml/ml.hpp>
#include <sstream>
#include <string>
#include <sys/stat.h>

#define BASEPATH "."
using namespace cv;
class Node {
public:
	long long get_left_child();
	static Node* getInstance(long long num);
	long long get_right_child();
	unsigned int get_level();
	long long get_num();
	virtual Mat* get_data()=0;
	virtual unsigned int predict(Mat sample,float& dist)=0;
	virtual ~Node();
protected :
	double num;
	double left;
	double right;
	int level;
	FileStorage* serialize();
};

#endif /* NODE_H_ */
