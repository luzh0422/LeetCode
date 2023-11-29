//
// Created by 陆泽辉 on 2023/9/24.
//

#include "LeetCode146.h"

LRUCache::LRUCache(int capacity) {
    _capacity = capacity;
}

void LRUCache::put(int key, int value) {
    auto it = uM.find(key);
    if (it == uM.end()) {
        if (_curr >= _capacity) {
            uM.erase(LRUList.back()->_key);
            LRUList.pop_back();
        }
        auto node = new Node(key, value);
        LRUList.push_front(node);
        uM.insert(unordered_map<int, list<Node *>::iterator>::value_type(key, LRUList.begin()));
        if (_curr < _capacity) {
            _curr++;
        }
    } else {
        auto iter = uM[key];
        LRUList.erase(iter);
        LRUList.push_front(new Node(key, value));
        uM[key] = LRUList.begin();
    }
}

int LRUCache::get(int key) {
    if (!uM.count(key)) {
        return -1;
    }
    auto iter = uM[key];
    auto value = (*iter)->_value;
    LRUList.erase(iter);
    LRUList.push_front(new Node(key, value));
    uM[key] = LRUList.begin();
    return value;
}
