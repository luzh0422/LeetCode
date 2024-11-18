//
// Created by luzehui on 2024/2/23.
//

#include "LeetCode2583.h"
#include <queue>
#include <vector>

using namespace std;

long long LeetCode2583::kthLargestLevelSum(TreeNode *root, int k) {
    vector<long long> arr;
    queue<TreeNode*> q;
    int count = 1;
    q.push(root);
    while (!q.empty()) {
        int temp = 0;
        long long currCount = 0ll;
        for (int i = 0; i < count; i++) {
            auto node = q.front();
            q.pop();
            currCount += (long long)(node->val);
            if (node->left) {
                q.push(node->left);
                temp++;
            }
            if (node->right) {
                q.push(node->right);
                temp++;
            }
        }
        arr.push_back(currCount);
        count = temp;
    }
    std::sort(arr.begin(), arr.end(), greater<long long>());
    return k > arr.size() ? -1 : arr[k - 1];
}
