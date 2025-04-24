//
// Created by luzehui on 24-12-17.
//

#include "LeetCode3291.h"

namespace {
    /**
     * 字典树是一棵多叉树；
     */
    struct Node {
        Node* nxt[26];
        Node() {
            memset(nxt, 0, sizeof(nxt));
        }
    };
}

int LeetCode3291::minValidStrings(vector<std::string> &words, std::string target) {
    /**
     * 构造字典树；
     */
    Node* root = new Node();
    for (const string& word : words) {
        Node* p = root;
        for (char c : word) {
            if (!p->nxt[c - 'a']) {
                p->nxt[c - 'a'] = new Node();
            }
            p = p->nxt[c - 'a'];
        }
    }
    /**
     * 向前动态规划，求值；
     */
    const int n = (int)target.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == INT_MAX) {
            continue;
        }
        Node* p = root;
        for (int j = i; j < n; j++) {
            if (!p->nxt[target[j] - 'a']) {
                break;
            }
            dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            p = p->nxt[target[j] - 'a'];
        }
    }
    if (dp[n] == INT_MAX) {
        return -1;
    }
    return dp[n];
}
