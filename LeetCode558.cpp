//
// Created by 陆泽辉 on 2022/7/18.
//

#include "LeetCode558.h"

//using namespace LEETCODE_LEETCODE558_H;

Node *LeetCode558::intersect(Node *quadTree1, Node *quadTree2) {
    Node* ret = new Node();
    if (quadTree1 == nullptr) {
        ret = quadTree2;
        return ret;
    }
    if (quadTree2 == nullptr) {
        ret = quadTree1;
        return ret;
    }
    if (quadTree1->isLeaf == 1 && quadTree1->val == 1 || quadTree2->isLeaf == 1 && quadTree2->val == 1) {
        ret->isLeaf = 1;
        ret->val = 1;
        return ret;
    }
    if (quadTree1->isLeaf == 1 && quadTree2->isLeaf == 1) {
        ret->isLeaf = 1;
        ret->val = quadTree1->val | quadTree2->val;
        return ret;
    }
    ret->isLeaf = 0;
    ret->val = 1;
    Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
    Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
    Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
    if (bottomLeft->isLeaf == 1 && bottomRight->isLeaf == 1 && topLeft->isLeaf == 1 && topRight->isLeaf == 1 && bottomLeft->val == bottomRight->val && bottomLeft->val == topRight->val && bottomLeft->val == topLeft->val) {
        ret->isLeaf = 1;
        ret->val = bottomLeft->val;
    } else {
        ret->bottomLeft = bottomLeft;
        ret->bottomRight = bottomRight;
        ret->topLeft = topLeft;
        ret->topRight = topRight;
    }
    return ret;
}

