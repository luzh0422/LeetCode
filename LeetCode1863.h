//
// Created by luzehui on 25-4-5.
//

#ifndef LEETCODE_LEETCODE1863_H
#define LEETCODE_LEETCODE1863_H

#include <vector>

using namespace std;

class LeetCode1863 {
public:
    int subsetXORSum(vector<int>& nums);

private:
    int subsetXORSum(vector<int>& nums, vector<bool>& visits, int num, int index);
};


#endif //LEETCODE_LEETCODE1863_H
