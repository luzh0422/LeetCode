//
// Created by luzh on 2021/11/21.
//

#include "Solution559.h"

using namespace MultiNodes;

int Solution559::maxDepth(Node *root) {
    if (root == nullptr) return 0;
    return maxDepth(root, 1);
}

int Solution559::maxDepth(Node *root, int curr) {
    if (root == nullptr) {
        return curr;
    }
    int ans = curr;
    for (auto child : root->children) {
        ans = max(ans, maxDepth(child, curr + 1));
    }
    return ans;
}
