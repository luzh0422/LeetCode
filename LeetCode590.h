//
// Created by 陆泽辉 on 2022/3/12.
//

#ifndef LEETCODE_LEETCODE590_H
#define LEETCODE_LEETCODE590_H

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

class LeetCode590 {
public:
    vector<int> postorder(Node* root);

private:
    void postorder(Node* root, vector<int> &arr);
};


#endif //LEETCODE_LEETCODE590_H
