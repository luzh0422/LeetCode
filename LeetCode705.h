//
// Created by luzehui on 2024/4/14.
//

#ifndef LEETCODE_LEETCODE705_H
#define LEETCODE_LEETCODE705_H

#include <vector>
#include <list>

using namespace std;

class MyHashSet {
public:
    MyHashSet();

    void add(int key);

    void remove(int key);

    bool contains(int key);

private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int num);
};

#endif //LEETCODE_LEETCODE705_H
