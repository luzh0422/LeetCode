//
// Created by luzh on 2021/10/19.
//

#include "Solution211.h"

void WordDictionary::addWord(string word) {
    Tire* node = tire;
    for (auto c : word) {
        c -= 'a';
        if (node->children[c] == nullptr) {
            node->children[c] = new Tire();
        }
        node = node->children[c];
    }
    node->isEnd = true;
}

bool WordDictionary::search(string word) {
    return dfs(word, 0, tire);
}

bool WordDictionary::dfs(string word, int index, Tire *node) {
    if (index == word.size() && node->isEnd) {
        return true;
    }
    char c = word[index];
    if (c >= 'a' && c <= 'z') {
        if (node->children[c - 'a'] == nullptr) {
            return false;
        }
        return dfs(word, index + 1, node->children[c - 'a']);
    } else if (c == '.') {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr && dfs(word, index + 1, node->children[i])) {
                return true;
            }
        }
    }
    return false;
}
