//
// Created by luzh on 2022/3/15.
//

#ifndef LEETCODE_LEETCODE2044_H
#define LEETCODE_LEETCODE2044_H

#include <vector>

using namespace std;

class LeetCode2044 {
public:
    int countMaxOrSubsets(vector<int>& nums);

private:
    int countMaxOrSubsets(vector<int>& nums, int currIndex, int currNum, int maxNum);
};


#endif //LEETCODE_LEETCODE2044_H
