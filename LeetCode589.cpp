//
// Created by luzh on 2022/3/10.
//

#include "LeetCode589.h"

vector<int> LeetCode589::preorder(Node *root) {
    vector<int> arr = {};
    preorder(root, arr);
    return arr;
}

void LeetCode589::preorder(Node *root, vector<int> &arr) {
    if (!root)
        return;
    arr.push_back(root->val);
    auto children = root->children;
    for (int i = 0; i < children.size(); i++) {
        preorder(children[i], arr);
    }
}
