//
// Created by luzehui on 2023/11/2.
//

#ifndef LEETCODE_LEETCODE117_H
#define LEETCODE_LEETCODE117_H

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class LeetCode117 {
public:
    Node* connect(Node* root);
};


#endif //LEETCODE_LEETCODE117_H
