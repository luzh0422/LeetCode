//
// Created by luzh on 2021/4/14.
//

#include "Solution208.h"

Trie::Trie(): children(26) {

}

void Trie::insert(string word) {
    Trie* node = this;
    for (char ch: word) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            node->children[ch] = new Trie();
        }
        node = node->children[ch];
    }
    node->isEnd = true;
}

Trie * Trie::searchPrefix(string word) {
    Trie* node = this;
    for (char ch : word) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            return nullptr;
        }
        node = node->children[ch];
    }
    return node;
}

bool Trie::search(string word) {
    Trie* node = this->searchPrefix(word);
    return node != nullptr && node->isEnd;
}

bool Trie::startsWith(string prefix) {
    Trie* node = this->searchPrefix(prefix);
    return node != nullptr;
}
