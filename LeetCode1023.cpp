//
// Created by 陆泽辉 on 2023/4/14.
//

#include "LeetCode1023.h"

vector<bool> LeetCode1023::camelMatch(vector<string> &queries, string pattern) {
    vector<bool> res{};
    buildTrie(pattern);
    for (auto query : queries) {
        auto temp = searchTrie(query);
        res.push_back(temp);
    }
    return res;
}

void LeetCode1023::buildTrie(string &pattern) {
    root = new Trie();
    auto curr = root;
    for (auto c : pattern) {
        curr->children.first = c;
        curr->children.second = new Trie();
        curr = curr->children.second;

    }
    curr->isEnd = true;
}

bool LeetCode1023::searchTrie(string &query) {
    auto curr = root;
    for (auto c : query) {
        if (c >= 'A' && c <= 'Z') {
            if (curr->children.first == c) {
                curr = curr->children.second;
            } else {
                return false;
            }
        } else {
            if (curr->children.first == c) {
                curr = curr->children.second;
            }
        }
    }
    return curr->isEnd;
}
