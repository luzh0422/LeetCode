//
// Created by 陆泽辉 on 2022/7/18.
//

#ifndef LEETCODE_LEETCODE558_H
#define LEETCODE_LEETCODE558_H

namespace LEETCODE_LEETCODE558_H {
    class Node {
    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;

        Node() {
            val = false;
            isLeaf = false;
            topLeft = nullptr;
            topRight = nullptr;
            bottomLeft = nullptr;
            bottomRight = nullptr;
        }
        Node(bool _val, bool _isLeaf) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = nullptr;
            topRight = nullptr;
            bottomLeft = nullptr;
            bottomRight = nullptr;
        }
        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = nullptr;
            topRight = nullptr;
            bottomLeft = nullptr;
            bottomRight = nullptr;
        }
    };
}

class LeetCode558 {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2);
};


#endif //LEETCODE_LEETCODE558_H
