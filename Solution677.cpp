//
// Created by luzh on 2021/11/14.
//

#include "Solution677.h"
#include <stack>

Solution677::Solution677() {
}

void Solution677::insert(string key, int val) {
    TreeNode* node = root;
    int n = key.size();
    for (int i = 0; i < n; i++) {
        char curr = key[i];
        if (node->children.count(key[i])) {
            node = node->children[key[i]];
        } else {
            node->children.insert(unordered_map<char, TreeNode*>::value_type(curr, new TreeNode()));
            node = node->children[key[i]];
        }
        if (i == n - 1) {
            node->val = val;
        }
    }
}

int Solution677::sum(string prefix) {
    int ans = 0;
    int n = prefix.size();
    TreeNode* node = root;
    for (int i = 0; i < n; i++) {
        char curr = prefix[i];
        if (node->children.count(curr)) {
            node = node->children[curr];
        } else {
            return 0;
        }
    }
    ans += node->val;
    stack<TreeNode*> stk = {};
    for (auto it = node->children.begin(); it != node->children.end(); it++) {
        stk.push(it->second);
    }
    while (!stk.empty()) {
        TreeNode* curr = stk.top();
        stk.pop();
        ans += curr->val;
        for (auto it = curr->children.begin(); it != curr->children.end(); it++) {
            stk.push(it->second);
        }
    }
    return ans;
}
