//
// Created by luzehui on 2024/2/17.
//

#ifndef LEETCODE_LEETCODE429_H
#define LEETCODE_LEETCODE429_H

#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class LeetCode429 {
public:
    vector<vector<int>> levelOrder(Node* root);
};


#endif //LEETCODE_LEETCODE429_H
