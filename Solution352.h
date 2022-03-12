//
// Created by luzh on 2021/10/9.
//

#ifndef LEETCODE_SOLUTION352_H
#define LEETCODE_SOLUTION352_H

#include <vector>
#include <map>

using namespace std;

class SummaryRanges {
public:
    SummaryRanges();

    void addNum(int val);

    vector<vector<int>> getIntervals();

private:
    map<int, int> cache;
};


#endif //LEETCODE_SOLUTION352_H
