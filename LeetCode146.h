//
// Created by 陆泽辉 on 2023/9/24.
//

#ifndef LEETCODE_LEETCODE146_H
#define LEETCODE_LEETCODE146_H

struct Node {
    int _key;
    int _value;
    Node(int key, int value) : _key(key), _value(value) {};
};

#include <list>
#include <unordered_map>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

private:
    list<Node*> LRUList;
    unordered_map<int, list<Node*>::iterator> uM;
    int _curr = 0;
    int _capacity = 0;
};


#endif //LEETCODE_LEETCODE146_H
