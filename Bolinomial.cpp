/*
 * Bolinomial.cpp
 *
 *  Created on: Jun 22, 2014
 *      Author: ortiga
 */

#include "Bolinomial.h"
#include <fstream>
#include "SVMNode.h"

Bolinomial::Bolinomial() {
	fstream tree("Polynomial\data.txt", std::ios_base::in);
	int id;
	while (tree >> id) {
		//(level,id)
		level_id[levelOfNode(id)] = id;
	}
	tree.close();
}

Bolinomial::~Bolinomial() {
	delete level_id;
}
void Bolinomial::consolidate(Node* node) {
	while (level_id.find(node->get_level()) != level_id.end()) {
		//merge 2 nodes
		node = new SVM_Node(
				getNodeFromDisk(level_id.find(node->get_level())->second),
				node);
		//remove node
		level_id.erase(node->get_level());
	}
	//level_id[node->get_level()]=node.getId();

}

int Bolinomial::perdict(Mat* test) {
	int retId = 0;
	float max = 0;
	for (map<int, int>::iterator it = level_id.begin(); it != level_id.end();
			++it) {
		Node* node = getNodeFromDisk(level_id[it->second]);
		while (node->get_level() != 1) { //not leaf
			if (node->predict(test, Mat()) == 0) { //go left

			} else { //go right

			}
		}
		if (node->predict(test, Mat()) > max)
			retId = node.getId();
	}
	return retId;
}
/**levelOfNode
 **@param id identifier of node
 **@return value #of levels in node correspondence to id
 **/
int levelOfNode(int id) {
	fstream info("id\info.txt", std::ios_base::in);
	int levels;
	info >> levels;
	info.close();
	return levels;
}

/** getNodeFromDisk
 ** @param id identifier of node
 ** @return value whole node correspondence to id
 **/
Node* getNodeFromDisk(int id) {
	//it's supposed to read whole node according to how we'll save it
	//if level 1 return knn node, else return svm
	return NULL;	//to skip warning :D
}

