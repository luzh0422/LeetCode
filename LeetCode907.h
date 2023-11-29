//
// Created by 陆泽辉 on 2022/10/28.
//

#ifndef LEETCODE_LEETCODE907_H
#define LEETCODE_LEETCODE907_H

#include <vector>

using namespace std;

class LeetCode907 {
public:
    int sumSubarrayMins(vector<int>& arr);

private:
    long countSubarray(long left, long right);
};


#endif //LEETCODE_LEETCODE907_H
