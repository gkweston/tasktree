/*
Add a log which keeps track of each iteration of the task tree as you complete it 
*/

#include "Tree.h"

Tree::Tree() : root(NULL) { }

Tree::Tree(Node* _rt) : root(_rt) { }

Tree::~Tree() {
    for (int i = 0; i < nodes.size(); ++i)
        delete nodes[i];
    delete root;
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

// void Tree::printFromNode(Node* nd) {
//     // (!) old, removing
//     // takes a node and prints downward, as if that node were the root to its own tasktree
//     std::cout << "~Key~\nParent: P<nid>, Node: (nid: task_name), Children: Node -> { Node }\n~~~~~\n";
//     std::queue<Node*> Q;
//     Q.push(nd);

//     while (!Q.empty()) {
//         if (Q.front()->type == node_type::PARENT) {
//             for (int i = 0; i < Q.front()->numChildren(); ++i)
//                 Q.push(Q.front()->children[i]);
//         }

//         Q.front()->printNodeAndChildren();
//         std::cout << std::endl;
//         Q.pop();
//     }
// }

// void Tree::updateNumLevels() { // (!) redundant?
//     int max_levels = 0;
//     for (auto n : nodes)
//         if (n->node_id.size() > max_levels) 
//             max_levels = n->node_id.size();

//     num_levels = max_levels;
// }

void Tree::print(Node* itr, std::string indent) {
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
        print(child, indent);
}

void Tree::print(std::string nid,std::string indent) {
    if (nid == "") {
        print(root, indent);
        return;
    }
    for (Node* n : nodes) {
        if (n->node_id == nid) {
            print(n, indent);
            return;
        }
    }
}

void Tree::printWithId(Node* itr, std::string indent) {
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
        printWithId(child, indent);
}

void Tree::printWithId(std::string nid, std::string indent) {
    if (nid == "") {
        printWithId(root, indent);
        return;
    }
    for (Node* n : nodes) {
        if (n->node_id == nid){
            printWithId(n, indent);
            return;
        }
    }
}

int Tree::writeToFile(std::string filename) {
    // clear given file
    std::ofstream outfile(filename, std::ofstream::out | std::ofstream::trunc);
    outfile.close();

    // write all relevant node attributes to file, node levels are encrypted by node_id format
    // this is then used in readFromFile() to reconstruct tree, simplifying this process
    outfile.open(filename);
    for (Node* n : nodes) {
        // outfile << n->node_id << "," << n->task_name << " ";
        outfile << n->node_id << ' ' << n->task_name << '\n';
    }
        
}

int Tree::readFromFile(std::string filename) {
    // read from file, using task_id to reconstruct tree

    // create root_node, set this->root = &root_node
    root = new Node(filename, "");
    
    // make vector of all node_id, task_name, find max(nid.size) for loop below
    std::ifstream inputfile(filename);
    std::string line, nid, tname;
    int max_nid_size = 0;
    while (std::getline(inputfile, line)) {
        std::stringstream ss(line);
        ss >> nid >> tname;
        nodes.push_back(new Node(nid, tname));

        if (max_nid_size < nid.size())
            max_nid_size = nid.size();
    }

    // for (Node* n : nodes) std::cout << n->task_name << std::endl;
    
    // iterate through nodes, if nid.size == 1 add as child of root
    int curr_nid_size = 1;
    for (Node* n : nodes) {
        if (n->node_id.size() == curr_nid_size)
            root.addChild(n);
    }

    // while i <= max_nid_size
    //     iterate through nodes, if nid.size == i++ add as child of nid[i-2]

    // while (curr_nid_size <= max_nid_size) {

    // }
    for (Node* n : nodes) {
        if (n->node_id.size() == ++curr_nid_size) {
            this->addNode(n->node_id[curr_nid_size-2], n);
        }

    }
    
    
    

    /*
    std::vector<std::pair<std::string, std::string>>> name_id_vec;
    while (getline(line, " "))
        while (getline(line_, ","))
            
    */

    // i = 1
    // make vector of all node_id.size=i
    // for each add child to root remove from vector of all nodes

    // make vector of all node_id.size=i++
    // for each add child to node_id[i - 1] remove from vector of all nodes

    // continue while vector of all nodes.size > 0
}