/*
 * Bolinomial.h
 *
 *  Created on: Jun 22, 2014
 *      Author: ortiga
 */

#ifndef BOLINOMIAL_H_
#define BOLINOMIAL_H_
using namespace std;
#include <vector>
#include "Node.h"
#include <map>

class Bolinomial {
public:
	Bolinomial();
	/**@Constructor
	 **/
	Bolinomial(char* name);
	/**@Destructor
	 **/
	virtual ~Bolinomial();
	/**consolidate
	 **@param node: node to be added
	 **node added and tree consolidated
	 **/
	void consolidate(Node* node);
	/**perdict
	 **@param test: matrix (image) to be classified
	 **@return the id of leaf node which perdicted
	 **/
	int perdict(Mat test);
	/**save
	 **save the binomial to file after consolidation finish
	 **/
	void save();
private:
	//map between level and id
	map<int, Node*> level_id;
};

#endif /* BOLINOMIAL_H_ */
