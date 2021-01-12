/*
Add a log which keeps track of each iteration of the task tree as you complete it 

Add a method that organizes by task time

Add add task time accumulation which establishes parent node time as the sum of all it's children
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Node.h"

#pragma once

class Tree {
	Node* root;
	std::vector<Node*> nodes;
	int num_levels;
public:
	Tree(Node* rt);
	~Tree();
	
	// each function is provided w/ an overloaded wrapper to take nodes by id
	// this way all nodes are store in nodes vector and user may interact w/ the
	// provided node id - this is quicker and easier than typing out task name

	// further nid tells us some important things:
	// id = "" iff node is root
	// id.size() = node level

	// gen node id's here, manage node_type LEAF -> PARENT
	void addNode(Node* parent, Node* chld);
	void addNode(std::string pid, Node* chld);
	// consolidate node id's here, manage node_type PARENT -> LEAF
	void removeNode(Node* chld);
	void removeNode(std::string pid);
	// for testing, remove
	void printFromNode(Node* nd);
	// use node_id.size() for determining max level and what level
	void updateNumLevels();
	// (!) consolidate these?
	void print(Node* itr, std::string indent="  ");
	void print(std::string nid, std::string indent="  ");
	void printWithId(Node* itr, std::string indent="  ");
	void printWithId(std::string nid, std::string indent="  ");
	

	// to do
	int writeToFile();
	int readFromFile();
	void updateNodeTypes(); // necessary? if a node is a parent and becomes a leaf, it should be popped...
	void makeTree();
	void changeTaskName();
	// this is in case AAA, AAB, AAC where AAB is removed and AAC -> AAB, may be handled as we go
	void consolidateNodeId();

	// test
	void testPrintNodes();
};