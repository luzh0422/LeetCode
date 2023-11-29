//
// Created by 陆泽辉 on 2022/6/7.
//

#ifndef LEETCODE_LEETCODE875_H
#define LEETCODE_LEETCODE875_H

#include <vector>

using namespace std;

class LeetCode875 {
public:
    int minEatingSpeed(vector<int>& piles, int h);

private:
    int totalHour(vector<int>& piles, int speed);
};

#endif //LEETCODE_LEETCODE875_H
