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
	 */
	void consolidate(Node* node);
	/**reset
	 ** reset add and remove vector to consolidate again
	 **/
	void reset();
	/**adjustPolynomial
	 ** use add and remove vectors to adjust new polynomial queue
	 **/
	void adjustPolynomial();
private:
	//nodes that should be added because of add new node (while consolidate)
	vector<int> add;
	//nodes that should be removed because of merging 2 nodes (while consolidate)
	vector<int> remove;
};

#endif /* BOLINOMIAL_H_ */
