#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

class Tree {
  Node* root;
  Node* common_node;
  bool complete;
  std::vector<Node> nodes_v;
public:
  
  Tree(Node* rt) : root(rt), common_node(NULL), complete(false) { }

  void addNode(std::string name) {
    
  }
};