//
// Created by luzh on 2021/7/10.
//

#ifndef LEETCODE_SOLUTION981_H
#define LEETCODE_SOLUTION981_H

#include <string>
#include <map>

using namespace std;

class Solution981 {};

class TimeMap {
public:
    TimeMap() {};
    void set(string key, string value, int timestamp);
    string get(string key, int timestamp);

private:
    map<string, map<int, string, less<int>>> storage = {};
};


#endif //LEETCODE_SOLUTION981_H
