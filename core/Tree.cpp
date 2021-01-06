/*
Add a log which keeps track of each iteration of the task tree as you complete it 
*/

#include "Tree.h"

Tree::Tree(Node* _rt) : root(_rt) { }

Tree::~Tree() {
    for (int i = 0; i < nodes.size(); ++i)
        delete nodes[i];
}

void Tree::addNode(Node* parent, Node* chld) {
    // use pid to find parent in nodes, instantiate new Node(...) here
    nodes.push_back(chld);
    parent->addChild(chld);
}

void Tree::addNode(std::string pid, Node* chld) {
    if (pid == "") {
        nodes.push_back(chld);
        root->addChild(chld);
        return;
    }
    for (Node* n : nodes) {
        if (n->node_id == pid) {
            nodes.push_back(chld);
            n->addChild(chld);
            return;
        }
    }
    std::cout << "No <" << pid << "> to add child\n";
}

void Tree::removeNode(Node* chld) {
    Node* n_parent = chld->parent;
    if (n_parent->removeChild(chld)){
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i]->node_id == chld->node_id)
                nodes.erase(nodes.begin() + i);
        }    
        if (n_parent->children.size() == 0 && n_parent->type != node_type::ROOT)
        removeNode(n_parent);
    } else {
        std::cout << "Tree::removeNode() failed.\n";
    }
}

void Tree::removeNode(std::string pid) {
    for (Node * n : nodes) {
        if (n->node_id == pid)
            removeNode(n);
   }

}

void Tree::printFromNode(Node* nd) {
    // takes a node and prints downward, as if that node were the root to its own tasktree
    std::cout << "~Key~\nParent: P<nid>, Node: (nid: task_name), Children: Node -> { Node }\n~~~~~\n";
    std::queue<Node*> Q;
    Q.push(nd);

    while (!Q.empty()) {
        if (Q.front()->isParent()) {
            for (int i = 0; i < Q.front()->numChildren(); ++i)
                Q.push(Q.front()->children[i]);
        }

        Q.front()->printNodeAndChildren();
        std::cout << std::endl;
        Q.pop();
    }
}

void Tree::updateNumLevels() {
    int max_levels = 0;
    for (auto n : nodes)
        if (n->node_id.size() > max_levels) 
            max_levels = n->node_id.size();

    num_levels = max_levels;
}

void Tree::prettyPrint(Node* itr, std::string indent) {
    std::string printstr = itr->task_name;

    if (itr->type == node_type::ROOT)
        std::cout << std::endl << printstr << std::endl;
    else {
        Node* p = itr->parent;
        int num_siblings = p->children.size();
        bool is_last_sibling = p->children[num_siblings - 1]->node_id == itr->node_id;

        std::cout << indent << (is_last_sibling ? "└╴" : "├╴") << printstr << std::endl;
        if (is_last_sibling && itr->children.size() == 0)
            std::cout << indent << std::endl;
            
        indent = indent + (is_last_sibling ? " " : "│ ");
    }

    for (auto child: itr->children)
        prettyPrint(child, indent);
}

void Tree::prettyPrint(std::string nid, std::string indent) {
    if (nid == "") {
        prettyPrint(root, indent);
        return;
    }
    for (Node* n : nodes) {
        if (n->node_id == nid)
            prettyPrint(n, indent);
    }
}

void Tree::prettyPrintWithId(Node* itr, std::string indent) {
    std::string printstr = itr->task_name + " <" + itr->node_id + ">";
 
    if (itr->type == node_type::ROOT)
        std::cout << std::endl << printstr << std::endl;
    else {
        Node* p = itr->parent;
        int num_siblings = p->children.size();
        bool is_last_sibling = p->children[num_siblings - 1]->node_id == itr->node_id;

        std::cout << indent << (is_last_sibling ? "└╴" : "├╴") << printstr << std::endl;
        if (is_last_sibling && itr->children.size() == 0)
            std::cout << indent << std::endl;
            
        indent = indent + (is_last_sibling ? " " : "│ ");
    }

    for (auto child: itr->children)
        prettyPrintWithId(child, indent);
}

void Tree::prettyPrintWithId(std::string nid, std::string indent) {
    if (nid == "") {
        prettyPrintWithId(root, indent);
        return;
    }
    for (Node* n : nodes) {
        if (n->node_id == nid)
            prettyPrintWithId(n, indent);
    }
}

void Tree::testPrintNodes() {
    std::cout << '\n';
    for (int i = 0; i < nodes.size(); ++i)
        std::cout << nodes[i]->node_id << " ";
    std::cout << '\n';
}

int Tree::writeToFile() {

}

int Tree::readFromFile() {

}
