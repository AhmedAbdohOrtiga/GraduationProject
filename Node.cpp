/*
 * Node.cpp
 *
 *  Created on: Jun 21, 2014
 *      Author: hazem
 */

#include "Node.h"
#include <algorithm>
#include "SVMNode.h"
#include "KNNNode.h"

FileStorage* Node::serialize()
{
	std::ostringstream f;
	f << BASEPATH;
	f<<'/';
	f << num;
	string dir = f.str();
	mkdir( dir.c_str() , S_IRWXU | S_IRWXG );

	f << "/attr.xml";

	FileStorage* fs = new FileStorage(f.str(),FileStorage::WRITE);

	*fs<<"level"<<level;
	*fs<<"num"<<num;

	return fs;

}

Node* Node::getInstance(long long num)
{
	std::ostringstream f;
	f << BASEPATH;
	f<<'/';
	f << (double)num;
	f <<"/attr.xml";
	string attr = f.str();

	FileStorage ff(attr,FileStorage::READ);
	int lev = 0;

	ff["level"] >> lev;


	if(lev == 0)
	{
		KNN_Node* nn = new KNN_Node();

		ff["num"] >>nn->num;
		ff["k"] >> nn->k;
		nn->data = new Mat();
		ff["data"] >> *(nn->data);

		ff["label"] >> nn->label;
		nn->left = 0;
		nn->right = 0;
		ff.release();
		nn->level = lev;

		return nn;
	}
	else
	{
		SVM_Node* nn = new SVM_Node();
		ff["num"] >> nn->num;
		ff["left"] >> nn->left;
		ff["right"] >> nn->right;
		ff["data_type"] >> nn->data_type;
		ff["feature_size"] >> nn->feature_size;

		std::ostringstream oss;
		oss << BASEPATH << '/' << (double) num << '/' << "model.xml";
		nn->svm.load(oss.str().c_str());
		ff.release();
		nn->level = lev;
		return nn;

	}


}

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

//Mat* Node::get_data()
//{
//	return NULL;
//}



//unsigned int Node::predict(const Mat sample,float& dist)
//{
//	return 0;
//}
Node::~Node()
{

}
