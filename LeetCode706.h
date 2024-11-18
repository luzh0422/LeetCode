//
// Created by luzehui on 2024/4/15.
//

#ifndef LEETCODE_LEETCODE706_H
#define LEETCODE_LEETCODE706_H

#include <vector>
#include <list>

using namespace std;

class MyHashMap {
public:
    MyHashMap();

    void put(int key, int value);

    int get(int key);

    void remove(int key);

private:
    vector<list<pair<int, int>>> data;
    static const int base = 769;
    static int hash(int num);
};

#endif //LEETCODE_LEETCODE706_H
