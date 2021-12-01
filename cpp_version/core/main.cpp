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
    Tree task_tree(new Node("root_task", ""));
    task_tree.addNode("", new Node("A_task", "a"));
    task_tree.addNode("a", new Node("AA_task", "aa"));
    task_tree.addNode("aa", new Node("AAA_task", "aaa"));
    task_tree.addNode("a", new Node("AB_task", "ab"));
    task_tree.addNode("a", new Node("AC_task", "ac"));
    task_tree.addNode("", new Node("B_task", "b"));
    task_tree.addNode("b", new Node("BA_task", "ba"));
    task_tree.addNode("b", new Node("BB_task", "bb"));
    task_tree.addNode("", new Node("C_task", "c"));
    task_tree.addNode("c", new Node("CA_task", "ca"));
    task_tree.addNode("ca", new Node("CAA_task", "caa"));

    cout << "Pretty print indent=default:\n";
    task_tree.print();

    cout << "Test file output to \"tasktree.tf\"\n";
    task_tree.writeToFile();

    // cout << "Make empty tt and read file, then print\n";
    cout << "\n\ndebugging\n\n";
    Tree task_tree_r;
    task_tree_r.readFromFile();
    // task_tree_r.print();
    
    
}