//
// Created by luzehui on 2024/1/9.
//

#include "LeetCode2707.h"
#include <unordered_set>

struct Node {
    Node *nxt[26];
    bool word;
    Node() {
        memset(nxt, NULL, sizeof(nxt));
        word = false;
    }
};

int LeetCode2707::minExtraChar(std::string s, vector<std::string> &dictionary) {
    /**
     * 构建字典树；
     */
    Node* root = new Node;
    for (const auto &w : dictionary) {
        Node *p = root;

        for (char c : w) {
            if (!p->nxt[c - 'a'])
                p->nxt[c - 'a'] = new Node;
            p = p->nxt[c - 'a'];
        }

        p->word  = true;
    }

    const int n = s.size();
    vector<int> f(n + 1, INT_MAX);
    f[0] = 0;

    for (int i = 0; i < n; i++) {
        f[i + 1] = min(f[i + 1], f[i] + 1);
        Node *p = root;
        for (int j = i + 1; j <= n; j++) {
            if (!p->nxt[s[j - 1] - 'a'])
                break;
            p = p->nxt[s[j - 1] - 'a'];
            if (p->word)
                f[j] = min(f[j], f[i]);
        }
    }
    return f[n];
}
