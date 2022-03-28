//
// Created by luzh on 2022/3/16.
//

#ifndef LEETCODE_LEETCODE432_H
#define LEETCODE_LEETCODE432_H

#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class AllOne {
public:
    AllOne();
    void inc(string key);
    void dec(string key);
    string getMaxKey();
    string getMinKey();

private:
    list<pair<unordered_set<string>, int>> lst;
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodes;
};

#endif //LEETCODE_LEETCODE432_H
