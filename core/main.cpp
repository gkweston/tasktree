/*
Run executable with flag such as
-a : add
-p : print
-m : merge
-c : complete
etc

*/

// test file for main

#include <iostream>
#include <vector>
#include <string>
#include "Node.h"
#include "Tree.h"
using namespace std;

int main() {
    Tree task_tree(new Node("root_task", "", node_type::ROOT));
    task_tree.addNode("", new Node("A_task", "a", node_type::PARENT));
    task_tree.addNode("a", new Node("AA_task", "aa", node_type::PARENT));
    task_tree.addNode("aa", new Node("AAA_task", "aaa", node_type::LEAF));
    task_tree.addNode("a", new Node("AB_task", "ab", node_type::LEAF));
    task_tree.addNode("a", new Node("AC_task", "ac", node_type::LEAF));
    task_tree.addNode("", new Node("B_task", "b", node_type::PARENT));
    task_tree.addNode("b", new Node("BA_task", "ba", node_type::LEAF));
    task_tree.addNode("b", new Node("BB_task", "bb", node_type::LEAF));
    task_tree.addNode("", new Node("C_task", "c", node_type::PARENT));
    task_tree.addNode("c", new Node("CA_task", "ca", node_type::PARENT));
    task_tree.addNode("ca", new Node("CAA_task", "caa", node_type::LEAF));

    task_tree.prettyPrint("");
    // task_tree.prettyPrintWithId(root);
}