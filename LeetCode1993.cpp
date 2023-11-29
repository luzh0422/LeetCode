//
// Created by 陆泽辉 on 2023/9/24.
//

#include "LeetCode1993.h"
#include <queue>

LockingTree::LockingTree(vector<int> &parent) {
    int n = parent.size();
    this->parent_.resize(n, -1);
    this->lockedUsers_.resize(n, -1);
    this->children_.resize(n);
    for (int i = 0; i < n; i++) {
        this->parent_[i] = parent[i];
        if (parent[i] != -1) {
            this->children_[parent[i]].push_back(i);
        }
    }
}

bool LockingTree::lock(int num, int user) {
    if (this->lockedUsers_[num] == -1) {
        this->lockedUsers_[num] = user;
        return true;
    }
    return false;
}

bool LockingTree::unlock(int num, int user) {
    if (this->lockedUsers_[num] == user) {
        this->lockedUsers_[num] = -1;
        return true;
    }
    return false;
}

bool LockingTree::upgrade(int num, int user) {
    if (this->lockedUsers_[num] != -1) {
        return false;
    }
    auto checkAncestors = [&]() -> bool {
        int temp = num;
        while(this->parent_[temp] != -1) {
            temp = this->parent_[temp];
            if (this->lockedUsers_[temp] != -1) {
                return false;
            }
        }
        return true;
    };
    auto checkDescendants = [&]() -> bool {
        std::queue<int> q;
        for (auto child : this->children_[num]) {
            q.push(child);
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (this->lockedUsers_[node] != -1) {
                return true;
            }
            for (auto child : this->children_[node]) {
                q.push(child);
            }
        }
        return false;
    };
    if (checkAncestors() && checkDescendants()) {
        this->lockedUsers_[num] = user;
        std::queue<int> q;
        for (auto child : this->children_[num]) {
            q.push(child);
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            this->lockedUsers_[node] = -1;
            for (auto child : this->children_[node]) {
                q.push(child);
            }
        }
        return true;
    }
    return false;
}
