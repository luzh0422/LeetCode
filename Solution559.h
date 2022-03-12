//
// Created by luzh on 2021/11/21.
//

#ifndef LEETCODE_SOLUTION559_H
#define LEETCODE_SOLUTION559_H

#include <vector>

using namespace std;

namespace MultiNodes {
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

    class Solution559 {
    public:
        int maxDepth(Node* root);

    private:
        int maxDepth(Node* root, int curr);
    };
}




#endif //LEETCODE_SOLUTION559_H
