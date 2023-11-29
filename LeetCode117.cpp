//
// Created by luzehui on 2023/11/2.
//

#include "LeetCode117.h"
#include <queue>

using namespace std;

Node *LeetCode117::connect(Node *root) {
    if (root == nullptr) {
        return root;
    }
    auto node = root;
    int count = 1;
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        int temp = 0;
        for (int i = 0; i < count - 1; i++) {
            auto curr = q.front();
            q.pop();
            auto next = q.front();
            if (curr->left) {
                q.push(curr->left);
                temp++;
            }
            if (curr->right) {
                q.push(curr->right);
                temp++;
            }
            curr->next = next;
        }
        auto next = q.front();
        q.pop();
        if (next->left) {
            q.push(next->left);
            temp++;
        }
        if (next->right) {
            q.push(next->right);
            temp++;
        }
        count = temp;
    }
    return root;
}
