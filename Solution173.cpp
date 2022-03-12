#include "Solution173.h"

BSTIterator::BSTIterator(TreeNode* root) {
    this->inOrder(root);
    curr = 0;
    length = this->store.size();
}

void BSTIterator::inOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    TreeNode* left = root->left;
    inOrder(left);
    store.push_back(root->val);
    TreeNode* right = root->right;
    inOrder(right);
}

bool BSTIterator::hasNext() {
    if (curr >= length) {
        return false;
    } else {
        return true;
    }
}

int BSTIterator::next() {
    int ans = store[curr];
    curr++;
    return ans;
}
