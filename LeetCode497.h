//
// Created by 陆泽辉 on 2022/6/9.
//

#ifndef LEETCODE_LEETCODE497_H
#define LEETCODE_LEETCODE497_H

#include <vector>

using namespace std;

class LeetCode497 {
public:
    LeetCode497(vector<vector<int>> &rects);

    vector<int> pick();

private:
    vector<int> sums;
    vector<vector<int>> mRects;
    int totalSum;
};


#endif //LEETCODE_LEETCODE497_H
