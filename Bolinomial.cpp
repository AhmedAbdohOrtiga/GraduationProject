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

}

Bolinomial::~Bolinomial() {
	delete add;
	delete remove;
}
void Bolinomial::consolidate(Node* node) {
	fstream tree("Polynomial\data.txt", std::ios_base::in);
	int id;
	while (tree >> id) {
		if (node->get_level() == levelOfNode(id)) { //2 nodes of same size, so merge
		//removed from polynomial queue
			remove.push_back(id);
			//remove.push_back(node->getID()); // should be added
			node = new SVM_Node(getNodeFromDisk(id), node);

		} else {//done (no more merge cause trees sorted in size so all next is greater)
			// add to polynomial queue
			//add.push_back(node->getID()); // should be added
			break;
		}
	}
	tree.close();

}

void Bolinomial::reset() {
	add.clear();
	remove.clear();
}

void Bolinomial::adjustPolynomial() {
	//will edit numbers which in polynomial file (don't know how yet)
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

