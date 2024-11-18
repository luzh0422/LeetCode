//
// Created by luzehui on 2024/4/15.
//

#include "LeetCode706.h"

MyHashMap::MyHashMap() {
    data = vector<list<pair<int, int>>>(base);
}

int MyHashMap::hash(int num) {
    return num % base;
}

void MyHashMap::put(int key, int value) {
    int hashVal = hash(key);
    for (auto iter = data[hashVal].begin(); iter != data[hashVal].end(); iter++) {
        if (iter->first == key) {
            iter->second = value;
            return;
        }
    }
    data[hashVal].push_back({key, value});
}

int MyHashMap::get(int key) {
    int hashVal = hash(key);
    for (auto iter = data[hashVal].begin(); iter != data[hashVal].end(); iter++) {
        if (iter->first == key) {
            return iter->second;
        }
    }
    return -1;
}

void MyHashMap::remove(int key) {
    int hashVal = hash(key);
    for (auto iter = data[hashVal].begin(); iter != data[hashVal].end(); iter++) {
        if (iter->first == key) {
            data[hashVal].erase(iter);
            return;
        }
    }
}
