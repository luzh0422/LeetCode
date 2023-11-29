//
// Created by 陆泽辉 on 2022/9/20.
//

#ifndef LEETCODE_LEETCODE689_H
#define LEETCODE_LEETCODE689_H

#include <vector>

using namespace std;

class LeetCode689 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k);

private:
    bool canPartitionKSubsets(vector<int> &nums, int k, int target, vector<int> &cache, int sum, int start);
};


#endif //LEETCODE_LEETCODE689_H
