//
// Created by luzh on 2022/3/10.
//

#ifndef LEETCODE_LEETCODE589_H
#define LEETCODE_LEETCODE589_H

#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;

    };
};

class LeetCode589 {
public:
    vector<int> preorder(Node* root);

private:
    void preorder(Node* root, vector<int>& arr);
};


#endif //LEETCODE_LEETCODE589_H
