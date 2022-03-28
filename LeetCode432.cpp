//
// Created by luzh on 2022/3/16.
//

#include "LeetCode432.h"

AllOne::AllOne() {}

void AllOne::inc(string key) {
    if (nodes.count(key)) {
        auto curr = nodes[key], nxt = next(curr);
        if (nxt == lst.end() || nxt->second > curr->second + 1) {
            unordered_set<string> s({key});
            nodes[key] = lst.emplace(nxt, s, curr->second + 1);
        } else {
            nxt->first.emplace(key);
            nodes[key] = nxt;
        }
        curr->first.erase(key);
        if (curr->first.empty()) {
            lst.erase(curr);
        }
    } else {
        if (lst.empty() || lst.begin()->second > 1) {
            unordered_set<string> s({key});
            lst.emplace_front(s, 1);
        } else {
            lst.begin()->first.emplace(key);
        }
        nodes[key] = lst.begin();
    }
}

void AllOne::dec(string key) {
    auto curr = nodes[key];
    if (curr->second == 1) {
        nodes.erase(key);
    } else {
        auto pre = prev(curr);
        if (curr == lst.begin() || pre->second < curr->second - 1) {
            unordered_set<string> s({key});
            nodes[key] = lst.emplace(curr, s, curr->second - 1);
        } else {
            pre->first.emplace(key);
            nodes[key] = pre;
        }
    }
    curr->first.erase(key);
    if (curr->first.empty()) {
        lst.erase(curr);
    }
}

string AllOne::getMaxKey() {
    return lst.empty() ? "" : *lst.rbegin()->first.begin();
}

string AllOne::getMinKey() {
    return lst.empty() ? "" : *lst.begin()->first.begin();
}
