//
// Created by luzehui on 2024/4/14.
//

#include "LeetCode705.h"

MyHashSet::MyHashSet() {
    data = vector<list<int>>(base);
}

int MyHashSet::hash(int num) {
    return num % base;
}

void MyHashSet::add(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
        if (*it == key) {
            return;
        }
    }
    data[h].push_back(key);
}

bool MyHashSet::contains(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
        if (*it == key) {
            return true;
        }
    }
    return false;
}

void MyHashSet::remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
        if (*it == key) {
            data[h].erase(it);
            return;
        }
    }
}
