//
// Created by luzh on 2021/6/7.
//

#ifndef LEETCODE_SOLUTION494_H
#define LEETCODE_SOLUTION494_H

#include <vector>

using namespace std;

class Solution494 {
public:
    Solution494() {}
    int findTargetSumWays(vector<int>& nums, int target);
private:
    void findTargetSumWays(vector<int>& nums, int target, int curr, int currIndex, int& ans);
};


#endif //LEETCODE_SOLUTION494_H
