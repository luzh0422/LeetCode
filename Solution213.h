//
// Created by luzh on 2021/4/15.
//

#ifndef LEETCODE_SOLUTION213_H
#define LEETCODE_SOLUTION213_H

#include <vector>

using namespace std;

class Solution213 {
public:
    Solution213() {}
    int rob(vector<int>& nums);

private:
    int rob(vector<int>& nums, int start, int end);
};


#endif //LEETCODE_SOLUTION213_H
