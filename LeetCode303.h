//
// Created by luzehui on 2024/3/18.
//

#ifndef LEETCODE_LEETCODE303_H
#define LEETCODE_LEETCODE303_H

#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums);

    int sumRange(int left, int right);

private:
    vector<int> preSums;
};

#endif //LEETCODE_LEETCODE303_H
