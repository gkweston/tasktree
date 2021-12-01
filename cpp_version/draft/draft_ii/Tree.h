/*
Add a log which keeps track of each iteration of the task tree as you complete it 
*/

#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

// parent id = pid; child id = cid

class Tree {
	Node* root;
	Node* common_node;
	bool complete;
	std::vector<Node> leaves;
public:

	Tree(Node* rt) : root(rt), common_node(NULL), complete(false) { }

	void addNode(std::string name, std::string pid) { }
	void updateParents() { }
	void markComplete(std::string cid) { }
	void removeComplete() {
		/* start at root and delete complete nodes */
		/* remove parent iff num_children = 0 */
	}
	void updateLeaves() {
		/* root-to-leaf and track all leaves to be marked */
	}
};