//
// Created by luzehui on 2024/2/17.
//

#include "LeetCode429.h"
#include <queue>

vector<vector<int>> LeetCode429::levelOrder(Node *root) {
    if (!root)
        return {};
    queue<Node*> q;
    q.push(root);
    int count = 1;
    vector<vector<int>> res;
    while (!q.empty()) {
        int temp = 0;
        vector<int> arr = {};
        for (int i = 0; i < count; i++) {
            auto node = q.front();
            q.pop();
            arr.push_back(node->val);
            for (int j = 0; j < node->children.size(); j++) {
                q.push(node->children[j]);
                temp++;
            }
        }
        count = temp;
        res.push_back(arr);
    }
    return res;
}
