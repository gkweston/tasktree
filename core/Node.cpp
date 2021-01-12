#include "Node.h"

// all nodes start as leaves except root - addChild changes to parent, parents who become leaves are popped (completed)
Node::Node(std::string _name, std::string _id) : task_name(_name), node_id(_id), parent(NULL) {
    if (_id == "")
        type = node_type::ROOT;
    else
        type = node_type::LEAF;
}

bool Node::hasSiblings() {
    if (type == node_type::ROOT) {
        return false;
    } 
    return this->parent->children.size() > 1;    
}

int Node::numSiblings() { return this->parent->children.size(); }

std::string Node::genNodeId() {
    // (!) this should be done by tree so it can be passed into constructor
    // is root explicitely assigned a node or assigned here
    // last_sid is node's last sibling's nid
    if (type == node_type::ROOT)
        // id = "" iff root
        return "";
    else if (parent->type == node_type::ROOT) {
        // base case for node_ids
        if (hasSiblings()) {
            // take last node on this level and make nid the next letter by ASCII
            std::string last_sid = parent->children[numSiblings() - 1]->node_id;
            return "" + (char)last_sid[0]++;
        } else {
            // first node added, start at A - gives node_id numbers a larger base than "a"
            return "A";
        }
    } else {
        if (hasSiblings()) {
            // increment the last sibling's node_id
            std::string last_sid = parent->children[numSiblings() - 1]->node_id;
            return parent->node_id + (char)last_sid[last_sid.size() - 1]++;
        } else {
            // first node on this level, start at "A"
            return parent->node_id + "A";
        }
    }
    // all should be accounted for - all member data should be established before calling genNodeId()
    std::cout << "Error generating node id\n";
}

int Node::numChildren() { return children.size(); }

void Node::addChild(Node* chld) {
    children.push_back(chld);
    chld->parent = this;
    
    if (type == node_type::LEAF)
        type = node_type::PARENT;
}

int Node::removeChild(Node* chld) {
    // ensure that child is leaf
    
    if (chld->type != node_type::LEAF) {
        std::cout << "ERROR: cannot remove non-leaf nodes\n";
        return 0;
    }

    for (int i = 0; i < children.size(); ++i) {
        if (children[i] == chld) {
            children.erase(children.begin() + i);
            break;
        }
    }

    if (children.size() == 0 && type != node_type::ROOT) 
        type = node_type::LEAF;

    return 1;
}

void Node::printNode() {
    std::cout << "(" << node_id << ": " << task_name << ") ";
}

void Node::printNodeAndChildren() {
    std::string pid = "r";
    if (parent)
        pid = parent->node_id;
    int space_num = 3 - pid.size(); // three is the current max node_id.size()
    std::string spaces = "";
    for (int i = 0; i < space_num; ++i)
        spaces.append(" ");

    std::cout << "P<" << pid << ">" << spaces << "(" << node_id << ": " << task_name << ") -> { ";

    for (int i = 0; i < children.size(); ++i)
        children[i]->printNode();

    std::cout << "}";
}

bool operator==(const Node& n1, const Node& n2) {
	if (n1.task_name != n2.task_name || n1.node_id != n2.node_id || n1.type != n2.type)
		return false;
	
	if (n1.children.size() != n2.children.size())
		return false;

	bool child_eq = true;
	for (int i = 0; i < n1.children.size(); ++i) {
		if (n1.children[i] != n2.children[i])
			return false;
	}

	return true;
}