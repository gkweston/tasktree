#include <iostream>
#include <string>
#include "Node.h"
	
/* Define as struct - data protected by private Tree it is part of */
struct Node {
// id is unique ID given by program, name is name of task
    std::string id, name;
    bool complete;

    // an array of pointers so it can be init w/o child values
    Node** children;
    Node* parent;
    size_t num_children;

    Node(std::string nid, std::string tname) {
        id = nid;
        name = tname;
        complete = false;
        children = NULL;
        parent = NULL;
        num_children = 0;
    }

    void addChild(Node* chld) {
        if (!num_children) {
            children = new Node*[1];
            children[0] = chld;
            ++num_children;
        } else if (num_children) {
            Node** temp = new Node*[num_children + 1];

            for (int i = 0; i < num_children; ++i)
                temp[i] = children[i];

            temp[num_children] = chld;
            ++num_children;

            delete[] children;
            children = temp;
        }
    }

    void removeChildByID(std::string cid) {
        if (!num_children) {
            return;
        } else if (num_children == 1) {
            delete children[0];
            delete[] children;
            children = NULL;
        } else {
            Node** temp = new Node*[num_children - 1];
            for (int i = 0; i < num_children; ++i) {
                if (children[i]->id != cid)
                    temp[i] = children[i];
                else 
                    delete children[i];
            }
            delete[] children;
            children = temp;
            num_children--;
        }
        
    }

};