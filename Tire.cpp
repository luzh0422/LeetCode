//
// Created by luzh on 2021/10/19.
//

#include "Tire.h"

Tire::Tire() {
    this->children = vector<Tire*>(26, nullptr);
    this->isEnd = false;
}

void Tire::insert(string word) {
    Tire* node = this;
    for (auto ch: word) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            node->children[ch] = new Tire();
        }
        /**
         * 通过node来实现的递归；
         */
        node = node->children[ch];
    }
    node->isEnd = true;
}

bool Tire::search(string word) {
    Tire* node = this;
    for (char ch: word) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            return false;
        }
        node = node->children[ch];
    }
    return node->isEnd == true;
}
