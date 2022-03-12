//
// Created by 陆泽辉 on 2022/3/12.
//

#include "LeetCode590.h"

vector<int> LeetCode590::postorder(Node *root) {
    vector<int> ret;
    postorder(root, ret);
    return ret;
}

void LeetCode590::postorder(Node *root, vector<int> &arr) {
    auto children = root->children;
    int size = children.size();
    for (int i = 0; i < size; i++) {
        postorder(children[i], arr);
    }
    arr.push_back(root->val);
}
