//
// Created by 陆泽辉 on 2023/3/24.
//

#include "LeetCode1032.h"

StreamChecker::StreamChecker(vector<string> &words) : root(new Trie()) {
    for (auto& word : words) {
        int n = word.size();
        auto node = root;
        for (int i = n - 1; i >= 0; i--) {
            char ch = word[i];
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
            if (i == 0) {
                node->isEnd = true;
            }
        }
    }
}

bool StreamChecker::query(char letter) {
    searchS += letter;
    currNum++;
    auto node = root;
    for (int i = currNum - 1; i >= 0; i--) {
        char c = searchS[i];
        if (node->children[c - 'a'] == nullptr) {
            break;
        }
        if (node->isEnd) {
            return true;
        }
        node = node->children[c - 'a'];
    }
    return node->isEnd;
}
