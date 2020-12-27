#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

/*
  Define as struct - data protected by private Tree it is part of
*/
struct Node {
  std::string id, name;
  bool complete, root, leaf;
  std::time_t datetime_created;
  // an array of pointers so it can be init w/o child values
  Node** children;
  size_t num_children;

  Node(std::string nid, std::string tname) {
    // nid, complete is assigned by program, not user
    // tree assigns nid
    id = nid;
    name = tname;
    complete = false;
    root = false;
    leaf = false;
    auto curr_time = std::chrono::system_clock::now();
    std::time_t datetime_created = std::chrono::system_clock::to_time_t(curr_time);
    children = NULL;
    num_children = 0;
    // to print time
    // cout << std::ctime(&stime) << endl;
  }

  void addChild(Node* chld) {
    if (!num_children) {
      children = new Node*[1];
      
      
    }
  }

};