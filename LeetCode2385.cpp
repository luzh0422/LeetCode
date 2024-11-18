//
// Created by luzehui on 2024/4/24.
//

#include "LeetCode2385.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int LeetCode2385::amountOfTime(TreeNode *root, int start) {
    if (!root) {
        return -1;
    }
    unordered_map<int, vector<int>> graph;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node->left) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            q.push(node->left);
        }
        if (node->right) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            q.push(node->right);
        }
    }
    int res = -1, count = 1;
    queue<int> qInt;
    qInt.push(start);
    unordered_set<int> uS;
    uS.insert(start);
    while (!qInt.empty()) {
        int temp = 0;
        res++;
        for (int i = 0; i < count; i++) {
            int node = qInt.front();
            qInt.pop();
            auto nexts = graph[node];
            for (auto next : nexts) {
                if (!uS.count(next)) {
                    uS.insert(next);
                    qInt.push(next);
                    temp++;
                }
            }
        }
        count = temp;
    }
    return res;
}
