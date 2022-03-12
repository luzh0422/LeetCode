//
// Created by luzh on 2021/7/22.
//

#ifndef LEETCODE_SOLUTION138_H
#define LEETCODE_SOLUTION138_H

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution138 {
    Node* copyRandomList(Node* head);
};


#endif //LEETCODE_SOLUTION138_H
