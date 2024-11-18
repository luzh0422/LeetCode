//
// Created by luzehui on 2024/6/8.
//

#ifndef LEETCODE_LEETCODE3040_H
#define LEETCODE_LEETCODE3040_H

#include <vector>

using namespace std;

class LeetCode3040 {
public:
    int maxOperations(vector<int>& nums);

private:
    int maxOperations(vector<int>& nums, int l, int r, vector<vector<int>>& dp, int target);
};


#endif //LEETCODE_LEETCODE3040_H
