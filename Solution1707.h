//
// Created by luzh on 2021/5/23.
//

#ifndef LEETCODE_SOLUTION1707_H
#define LEETCODE_SOLUTION1707_H

#include <vector>

using namespace std;

class Tire {
public:
    const int L = 30;
    Tire* children[2] = {};

    void insert(int val);
    int getMaxXor(int val);
};

class Solution1707 {
public:
    Solution1707() {}
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries);
};


#endif //LEETCODE_SOLUTION1707_H
