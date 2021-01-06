#include <iostream>
#include <string>
#include <vector>

#pragma once

/* make the tree by having nodes with a vector of children */

/* add task time to each node which can better describe parents */

enum node_type {ROOT, PARENT, LEAF};

struct Node {
	std::string task_name; // taskname
	std::string node_id;
	node_type type;
	std::vector<Node*> children;
	Node* parent;

	// node types should be handled in tree processes
	Node(std::string _name, std::string _id, node_type _type);
	
	bool hasSiblings();
	int numSiblings();
	std::string genNodeId();
	bool isParent();
	int numChildren();
	// add/remove children from parent to ensure consistancy in std::vector<Node*> children
	void addChild(Node* chld);
	int removeChild(Node* chld);
	void printNode();
	void printNodeAndChildren();
};

bool operator==(const Node& n1, const Node& n2);