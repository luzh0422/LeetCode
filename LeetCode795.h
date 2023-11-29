//
// Created by 陆泽辉 on 2022/11/24.
//

#ifndef LEETCODE_LEETCODE795_H
#define LEETCODE_LEETCODE795_H

#include <vector>

using namespace std;

class LeetCode795 {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right);

private:
    int numSubarrayBoundedMax(vector<int>& nums, int right);
};


#endif //LEETCODE_LEETCODE795_H
