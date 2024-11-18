//
// Created by luzehui on 2024/6/30.
//

#ifndef LEETCODE_LEETCODE494_H
#define LEETCODE_LEETCODE494_H

#include <vector>

using namespace std;

class LeetCode494 {
public:
    int findTargetSumWays(vector<int>& nums, int target);

private:
    int dfs(vector<int>& nums, int target, int index, int res);
};


#endif //LEETCODE_LEETCODE494_H
