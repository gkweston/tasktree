#include <iostream>
#include <string>
#include <vector>

#pragma once

/* make the tree by having nodes with a vector of children */

/* add task time to each node which can better describe parents */

enum node_type {ROOT, PARENT, LEAF};

struct Node {
	node_type type;
	std::string node_id;
	std::string task_name; // taskname
	Node* parent;
	std::vector<Node*> children;


	// all nodes start as leaves except root - addChild changes to parent, parents who become leaves are popped (completed)
	Node(std::string _name, std::string _id);
	
	bool hasSiblings();
	int numSiblings();
	std::string genNodeId();
	int numChildren();
	// add/remove children from parent to ensure consistancy in std::vector<Node*> children
	void addChild(Node* chld);
	int removeChild(Node* chld);
	void printNode(); //(!) remove
	void printNodeAndChildren(); // (!) remove
};

bool operator==(const Node& n1, const Node& n2);