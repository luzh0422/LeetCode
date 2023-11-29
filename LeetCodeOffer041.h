//
// Created by 陆泽辉 on 2022/7/16.
//

#ifndef LEETCODE_LEETCODEOFFER041_H
#define LEETCODE_LEETCODEOFFER041_H

#include <vector>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size);

    double next(int val);

private:
    vector<int> nums;
    int sum = 0, distance, currDis = 0, index = 0;
};

#endif //LEETCODE_LEETCODEOFFER041_H
