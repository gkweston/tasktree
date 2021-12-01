#include <iostream>
#include <string>
/* Define as struct - data protected by private Tree it is part of */
struct Node {
// id is unique ID given by program, name is name of task
	std::string id, name;
	bool complete;

	// an array of pointers so it can be init w/o child values
	Node** children;
	Node* parent;
	size_t num_children;

	Node(std::string nid, std::string tname);
	void addChild(Node* chld);
	void removeChildByID(std::string cid);

};