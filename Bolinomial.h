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
	/**@Constructor
	 **/
	Bolinomial();
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
	int perdict(Mat* test);
private:
	//map between level and id
	map<int, int> level_id;
};

#endif /* BOLINOMIAL_H_ */
