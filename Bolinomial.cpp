/*
 * Bolinomial.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: ortiga
 */

#include "Bolinomial.h"
#include <fstream>
#include "SVMNode.h"
#include "KNNNode.h"
#include "Node.h"
#include <stdlib.h>

Node* getNodeFromDisk(int id);

Bolinomial::Bolinomial() {
	srand(time(NULL));
	ifstream tree("data.txt");
	if (tree) {
		int id;
		while (tree >> id) {
			//(level,id)
			Node* node = Node::getInstance(id);
			level_id[node->get_level()] = node;
		}
	} else {
		ofstream tree("data.txt");

	}

	tree.close();
}

Bolinomial::~Bolinomial() {
	delete &level_id;
}

void Bolinomial::save() {
	//write new binomial to file before destructionu
	ofstream file("data.txt");
	for (map<int, Node*>::iterator it = level_id.begin(); it != level_id.end();
			++it) {
		file << it->second->get_num() << " ";
	}
	file.close();
}
void Bolinomial::consolidate(Node* node) {
	while (level_id.find(node->get_level()) != level_id.end()) {
		//merge 2 nodes
		int lev = node->get_level();
		node = new SVM_Node(level_id[node->get_level()], node,
				rand() % ULLONG_MAX);
		//remove node
		level_id.erase(lev);
	}
	level_id[node->get_level()] = node;

}

int Bolinomial::perdict(Mat test) {
	int retId = 0;
	float min = ULLONG_MAX;
	for (map<int, Node*>::iterator it = level_id.begin(); it != level_id.end();
			++it) {
		Node* node = it->second;
		float val;
		while (node->get_level() != 0) { //not leaf
			if (node->predict(test, val) == 0) { //go left
				node = Node::getInstance(node->get_left_child());
			} else {
				node = Node::getInstance(node->get_right_child());
			}
		}
		int id = node->predict(test, val);
		if (val < min)
			retId = id;
	}
	return retId;
}

/** getNodeFromDisk
 ** @param id identifier of node
 ** @return value whole node correspondence to id
 **/
Node* getNodeFromDisk(int id) {
	//it's supposed to read whole node according to how we'll save it
	//if level 1 return knn node, else return svm
	Node* returnNode = Node::getInstance(id);
	return returnNode;			//to skip warning
}

