//
// Created by luzehui on 2024/4/22.
//

#ifndef LEETCODE_LEETCODE377_H
#define LEETCODE_LEETCODE377_H

#include <vector>

using namespace std;

class LeetCode377 {
public:
    int combinationSum4(vector<int>& nums, int target);

private:
    int combinationSum4(vector<int>& nums, int target, int curr);
};


#endif //LEETCODE_LEETCODE377_H
