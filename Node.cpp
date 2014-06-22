/*
 * Node.cpp
 *
 *  Created on: Jun 21, 2014
 *      Author: hazem
 */

#include "Node.h"
#include <algorithm>

long long Node::get_left_child()
{
	return left;
}

long long Node::get_num()
{
	return num;
}

long long Node::get_right_child()
{
	return right;
}

unsigned Node::get_level(){
	return level;
}

Mat* Node::get_data()
{
	return NULL;
}
unsigned int Node::predict(const Mat sample,Mat* results)
{
	return 0;
}
Node::~Node()
{

}
