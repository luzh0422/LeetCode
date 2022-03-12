//
// Created by luzh on 2021/6/20.
//

#include "Solution1600.h"
#include <queue>
#include <stack>

ThroneInheritance::ThroneInheritance(string kingName) {
    root = new Node(kingName);
    record[kingName] = root;
}

void ThroneInheritance::birth(string parentName, string childName) {
//    queue<Node*> q;
//    q.push(root);
//    while (!q.empty()) {
//        Node* curr = q.front();
//        q.pop();
//        if (curr->_name == parentName) {
//            curr->children.push_back(new Node(childName));
//            break;
//        } else {
//            vector<Node*> children = curr->children;
//            for (int i = 0; i < children.size(); i++) {
//                q.push(children[i]);
//            }
//        }
//    }
    Node* parentNode = record[parentName];
    if (parentNode != nullptr) {
        Node* childNode = new Node(childName);
        parentNode->children.push_back(childNode);
        record[childName] = childNode;
    }
}

void ThroneInheritance::death(string name) {
//    queue<Node*> q;
//    q.push(root);
//    while (!q.empty()) {
//        Node* curr = q.front();
//        q.pop();
//        if (curr->_name == name) {
//            curr->alive = false;
//            break;
//        } else {
//            vector<Node*> children = curr->children;
//            for (int i = 0; i < children.size(); i++) {
//                q.push(children[i]);
//            }
//        }
//    }
    Node* currNode = record[name];
    if (currNode != nullptr) {
        currNode->alive = false;
    }
}

vector<string> ThroneInheritance::getInheritanceOrder() {
    vector<string> ans = {};
    stack<Node*> stk = {};
    stk.push(root);
    while (!stk.empty()) {
        Node* curr = stk.top();
        stk.pop();
        if (curr->alive) {
            ans.push_back(curr->_name);
        }
        vector<Node*> children = curr->children;
        for (int i = children.size() - 1; i >= 0; i--) {
            stk.push(children[i]);
        }
    }
    return ans;
}
